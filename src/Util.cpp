//
// Created by Lucas on 12/11/2022.
//

#include <shlobj.h>
#include "Util.h"

std::string Util::GetWindowsComputerName() {
    TCHAR infoBuf[INFO_BUFFER_SIZE];
    DWORD bufCharCount = INFO_BUFFER_SIZE;

    GetComputerName(infoBuf, &bufCharCount);

    return std::string(infoBuf);
}

std::string Util::GetExecutableName() {
#if defined(PLATFORM_POSIX) || defined(__linux__) //check defines for your setup
    std::string sp;
    std::ifstream("/proc/self/comm") >> sp;
    return sp;
#elif defined(_WIN32)
    char buf[MAX_PATH];
    GetModuleFileNameA(nullptr, buf, MAX_PATH);
    return buf;
#else
    static_assert(false, "unrecognized platform");
#endif
}

std::string Util::GetDocumentsFolderPath() {
    wchar_t Folder[1024];
    HRESULT hr = SHGetFolderPathW(0, CSIDL_MYDOCUMENTS, 0, 0, Folder);
    if (SUCCEEDED(hr))
    {
        char str[1024];
        wcstombs(str, Folder, 1023);
        return str;
    }
    else return "";
}
