//
// Created by Lucas on 12/11/2022.
//

#ifndef MYSECRETPROJECT_UTIL_H
#define MYSECRETPROJECT_UTIL_H

#include <string>
#include <windows.h>

#define INFO_BUFFER_SIZE 32767

class Util {
public:
    static std::string GetWindowsComputerName();
    static std::string GetExecutableName();
    static std::string GetDocumentsFolderPath();
};


#endif //MYSECRETPROJECT_UTIL_H
