#ifndef KRAKEN_MEMORY_BUFFER_H
#define KRAKEN_MEMORY_BUFFER_H

#include <cassert>
#include <cstdint>
#include <iostream>
#include <new>

namespace mem {

class buffer {

    wchar_t *m_begin, *m_end;

public:
    // default ctor.
    buffer(std::size_t sz) noexcept;

    buffer(const buffer &) = delete;
    buffer &operator=(const buffer &) = delete;

    // \brief Tests if the allocation was successful.
    inline bool failed() const noexcept {
        return m_begin == nullptr;
    }

    // \brief Get the size of the memory allocation.
    inline std::size_t size() const noexcept {
        return std::size_t(m_end - m_begin);
    }

    // \brief Returns a pointer to this buffers pointer.
    inline wchar_t *data() const noexcept {
        return m_begin;
    }

    // \brief Iterator support
    inline wchar_t *begin() const noexcept {
        return m_begin;
    }
    inline wchar_t *end() const noexcept {
        return m_end;
    }

    // \brief Get character from the buffer
    inline wchar_t get(std::size_t index) const {
        if (index >= this->size())
            throw std::out_of_range("buffer::get(std::size_t): index would cause dereference outside of buffer.");
        return m_begin[index];
    }
};

} // namespace mem

std::wostream &operator<<(std::wostream &os, const mem::buffer &b);

#endif // KRAKEN_MEMORY_BUFFER_H
