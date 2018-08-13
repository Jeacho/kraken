#ifndef KRAKEN_IO_PATH_H
#define KRAKEN_IO_PATH_H

#include <cassert>
#include <cstring>
#include <string>

#include "kraken/support/compiler.h"
#include "kraken/adt/segment.h"

#if defined(MACOS) || defined(LINUX)
# include <sys/stat.h>
#elif defined(WINDOWS)
# include <io.h>
# include <windows.h>
#endif

namespace fs {

namespace detail {

    template<typename char_type>
    using basic_segment = ::detail::basic_segment<char_type>;

template<typename char_type>
struct basic_path : public basic_segment<char_type> {
    typedef char_type           value_type;
    typedef char_type *         pointer;
    typedef const char_type *   const_pointer;
    typedef char_type &         reference;
    typedef const char_type &   const_reference;
    typedef std::size_t         size_type;
    typedef std::ptrdiff_t      difference_type;

    constexpr basic_path() noexcept
         : basic_segment<char_type>() { /* pass */ }

    basic_path(const std::string &str) noexcept
         : basic_segment<char_type>(str.data(), str.size()) { /* pass */ }

    constexpr basic_path(const_pointer be, const_pointer en) noexcept
         : basic_segment<char_type>(be, difference_type(en - be)) {
        assert(be < en);
    }

    constexpr basic_path(const char *cstr, std::size_t len) noexcept
         : basic_segment<char_type>(cstr, len) { /* pass */ }

    constexpr basic_path(pointer cstr) noexcept
         : basic_segment<char_type>(cstr) { /* pass */ }

    // \brief Portable basic_path check to see if this basic_path is a file.
    bool is_file() const noexcept {
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

    // \brief Portable basic_path check to see if this basic_path is a directory.
    bool is_dir() const noexcept {
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

    // \brief See if this basic_path exists
    bool exists() const noexcept {
#if defined(MACOS) || defined(LINUX)
        struct stat s;
        return (stat(this->data(), &s) == 0);
#elif defined(WINDOWS)
        DWORD fileAttributes = GetFileAttributesA(this->data());

        if (fileAttributes == INVALID_FILE_ATTRIBUTES)
            return false;

        return true;
#else
        platform_error();
#endif
    }

    // \brief Extracts the files extension from this basic_path.
    // NOTE: if no extension is provided a empty basic_path is returned.
    basic_path extension() const noexcept {
        if (this->empty())
            return basic_path{};

        for (char *index = this->end(); index != this->begin(); index--) {
            switch (*index) {
            case '.':
                if (index != 0 && *(index - 1) != '.')
                    return basic_path(index, this->end());

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

        return basic_path{};
    }
};

} // namespace detail

typedef detail::basic_path<char>        path;
typedef detail::basic_path<wchar_t>     wpath;
typedef detail::basic_path<char16_t>    u16path;
typedef detail::basic_path<char32_t>    u32path;

} // namespace fs

#endif // KRAKEN_IO_PATH_H
