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
    constexpr path() noexcept
         : m_data(nullptr), m_length(0) { /*pass */}

    path(const std::string &str) noexcept
         : m_data(str.data()), m_length(str.size()) { /* pass */ }

    constexpr path(const char *be, const char *en) noexcept
         : m_data(be), m_length(en - be) {
        assert(be < en);
    }

    constexpr path(const char *cstr, std::size_t len) noexcept
         : m_data(cstr), m_length(len) {
        /* pass */
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
        return this->data() == nullptr;
    }

    // \brief Iterator access to the path as a sequence of elements.
    constexpr inline char *begin() const {
        return const_cast<char *>(this->data());
    }
    constexpr inline char *end() const {
        return const_cast<char *>(this->data()) + this->size();
    }

    const char *c_str()     const { return m_data;              } 
    std::string str()       const { return std::string(m_data); }
    operator std::string()  const { return str();               }

    // \brief Portable path check to see if this path is a file.
    bool is_file() const noexcept;

    // \brief Portable path check to see if this path is a directory.
    bool is_dir() const noexcept;

    // \brief See if this path exists
    bool exists() const noexcept;

    // \brief Extracts the files extension from this path.
    // NOTE: if no extension is provided a empty path is returned.
    path extension() const noexcept;
};

} // namespace fs

#endif // KRAKEN_IO_PATH_H
