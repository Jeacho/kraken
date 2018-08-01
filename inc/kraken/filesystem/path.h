#ifndef KRAKEN_IO_PATH_H
#define KRAKEN_IO_PATH_H

#include <cassert>
#include <cstring>
#include <string>

#include "kraken/support/compiler.h"

#if defined(MACOS) || defined(LINUX)
# include <sys/stat.h>
#elif defined(WINDOWS)
# include <io.h>
# include <windows.h>
#endif

namespace fs {

class path {
    const char *m_data;

    const std::size_t m_length;

public:
    path(const std::string &str) noexcept
         : m_data(str.data()), m_length(str.size()) { /* pass */ }

    constexpr path(const char *cstr, std::size_t len) noexcept
         : m_data(cstr), m_length(len) {
        assert(cstr != nullptr
            && "nullptr cannot be provided for path::path(const char *)");
    }

    constexpr path(const char *cstr) noexcept
         : path(cstr, std::strlen(cstr)) { /* pass */ }

    // \brief Returns the length of this path's string.
    constexpr inline std::size_t size() const noexcept {
        return m_length;
    }

    // \brief Returns a pointer to this path's string.
    constexpr inline const char *data() const noexcept {
        return m_data;
    }

    // \brief Returns if this path is empty
    constexpr inline bool empty() const noexcept {
        return this->size() == 0ul;
    }

    // \brief Iterator access to the path as a sequence of elements.
    constexpr inline const char *begin() const {
        return this->data();
    }
    constexpr inline const char *end() const {
        return this->data() + this->size();
    }

    // \brief Portable path check to see if this path is a file.
    bool is_file() noexcept;

    // \brief Portable path check to see if this path is a directory.
    bool is_dir() noexcept;

    // \brief See if this path exists
    bool exists() noexcept;
};

} // namespace fs

#endif // KRAKEN_IO_PATH_H
