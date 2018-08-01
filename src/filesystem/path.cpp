
#include "kraken/filesystem/path.h"

using namespace fs;

bool path::is_file() noexcept {
#if defined(MACOS) || defined(LINUX)
    struct stat s;
    if(stat(this->data(), &s) != 0)
        return false;
    return S_ISREG(s.st_mode);
#elif defined(WINDOWS)
    DWORD file_attributes = GetFileAttributesA(this->data());

    if (file_attributes == INVALID_FILE_ATTRIBUTES)
        return false;

    if (file_attributes == FILE_ATTRIBUTE_NORMAL
     || file_attributes == FILE_ATTRIBUTE_ARCHIVE)
        return true;

    return false;
#else
    platform_error();
#endif
}

bool is_dir(const char *p) noexcept {
#if defined(MACOS) || defined(LINUX)
    struct stat s;
    if(stat(p, &s) != 0)
        return false;
    return S_ISDIR(s.st_mode);
#elif defined(WINDOWS)
    DWORD fileAttributes = GetFileAttributesA(p);

    if (fileAttributes == INVALID_FILE_ATTRIBUTES)
        return false;

    if (fileAttributes == FILE_ATTRIBUTE_DIRECTORY)
        return true;

    return false;
#else
    platform_error();
#endif
}

bool path::exists() noexcept {
#if defined(MACOS) || defined(LINUX)
    struct stat s;
    return (stat(p, &s) == 0);
#elif defined(WINDOWS)
    DWORD fileAttributes = GetFileAttributesA(this->data());

    if (fileAttributes == INVALID_FILE_ATTRIBUTES)
        return false;

    return true;
#else
    platform_error();
#endif
}
