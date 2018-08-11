
#include "kraken/memory/buffer.h"

using namespace mem;

buffer::buffer(std::size_t sz) noexcept {
    m_begin = new (std::nothrow) wchar_t [sz + 1];

    if (m_begin) {
        m_end = m_begin + sz + 1;
        m_begin[sz] = '\0';
    } else {
        // allocation failed.
        m_begin = m_end = nullptr;
    }
}

std::wostream &operator<<(std::wostream &os, const buffer &b) {
    assert(!b.failed());
    return os << std::wstring(b.begin(), b.size());
}
