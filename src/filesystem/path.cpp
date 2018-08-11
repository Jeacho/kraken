
#include "kraken/filesystem/path.h"

using namespace fs;

bool path::is_file() const noexcept {
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

bool path::is_dir() const noexcept {
#if defined(MACOS) || defined(LINUX)
    struct stat s;
    if(stat(this->data(), &s) != 0)
        return false;
    return S_ISDIR(s.st_mode);
#elif defined(WINDOWS)
    DWORD fileAttributes = GetFileAttributesA(this->data());

    if (fileAttributes == INVALID_FILE_ATTRIBUTES)
        return false;

    if (fileAttributes == FILE_ATTRIBUTE_DIRECTORY)
        return true;

    return false;
#else
    platform_error();
#endif
}

bool path::exists() const noexcept {
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

path path::extension() const noexcept {
    if (this->empty())
        return path{};

    for (char *index = this->end(); index != this->begin(); index--) {
        switch (*index) {
        case '.':
            if (index != 0 && *(index - 1) != '.')
                return path(index, this->end());

        case '\a': case '\b': case '\t': case '\n':
        case '\v': case '\f': case '\r':

#if defined(__clang__)
        case '\e':
#endif

        case '\0': case '\\': case '/': case '*':
        case '<': case '>': case '|': case '\"':
            break;

        }
    }

    return path{};
}
