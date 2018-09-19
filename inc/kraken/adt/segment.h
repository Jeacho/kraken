#ifndef KRAKEN_ADT_SEGMENT_H
#define KRAKEN_ADT_SEGMENT_H

#include <string>

namespace detail {

template<typename char_type>
class basic_segment {
public:
    typedef char_type           value_type;
    typedef char_type *         pointer;
    typedef const char_type *   const_pointer;
    typedef char_type &         reference;
    typedef const char_type &   const_reference;
    typedef std::size_t         size_type;
    typedef std::ptrdiff_t      difference_type;

private:
    // \brief The segments string data.
    const_pointer m_data;

    // \brief The length of this segment.
    size_type m_size;

public:
    static constexpr size_type npos = size_type(-1);

    constexpr basic_segment() noexcept
         : m_data(nullptr), m_size(0) { /* pass */ }

    constexpr basic_segment(const_pointer s, size_type c)
         : m_data(s), m_size(c) { /* pass */ }

    constexpr basic_segment(const_pointer s)
         : m_data(s), m_size(std::char_traits<value_type>::length(s))
         { /* pass */ }

    constexpr basic_segment(const basic_segment &other) noexcept = default;

    // \brief Returns a pointer to this segments data.
    constexpr inline const_pointer data() const noexcept { return m_data; }
    constexpr inline pointer data() noexcept { return const_cast<pointer>(m_data); }

    // \brief Returns the number of characters.
    constexpr inline size_type size()      const noexcept { return m_size; }
    constexpr inline size_type length()    const noexcept { return m_size; }

    // \brief Check whether this segment is empty.
    constexpr inline bool empty() const noexcept { this->size() == 0; }

    // \brief Returns a segment of this segment.
    constexpr basic_segment<value_type> substr(size_type pos = 0,
                                               size_t count = npos) const {
        if (pos > size())
            throw std::out_of_range("segment<T>::substr");
        size_type len = std::min(count, size() - pos);
        return basic_segment<value_type>(this->data() + pos, len);
    }

    // \brief Element access
    constexpr inline const_reference operator[](size_type pos) const {
        return m_data[pos];
    }

    // \brief Exception-checked element access.
    constexpr inline const_reference at(size_type pos) const {
        if(__builtin_expect(pos >= this->size(), 0))
            throw std::out_of_range("segment<T>::at");
        return m_data[pos];
    }

    // \brief See if this segment starts with the given prefix.
    constexpr bool starts_with(const basic_segment &prefix) noexcept {
        if (prefix.size() >= this->size())
            return false;

        for (std::size_t index = 0; index < prefix.size(); ++index)
            if (this->operator[](index) != prefix[index])
                return false;
        return true;
    }

    constexpr bool starts_with(const value_type prefix) noexcept {
        return starts_with(basic_segment<char_type>(&prefix, 1));
    }

    constexpr bool starts_with(const_pointer prefix) {
        return starts_with(basic_segment<char_type>(prefix));
    }

    inline operator const_pointer()  const noexcept { return this->data(); }
    inline operator pointer()        noexcept { return this->data(); }
};

} // namespace detail

template<typename char_type>
std::basic_ostream<char_type> &operator<<(std::basic_ostream<char_type> &os,
        const detail::basic_segment<char_type> &s) {
    return os << std::basic_string<char_type>(s.data(), s.length());
}

typedef detail::basic_segment<char>     segment;
typedef detail::basic_segment<wchar_t>  wsegment;
typedef detail::basic_segment<char16_t> u16segment;
typedef detail::basic_segment<char32_t> u32segment;

#endif // KRAKEN_ADT_SEGMENT_H
