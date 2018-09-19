#ifndef KRAKEN_LEXER_LEXER_H
#define KRAKEN_LEXER_LEXER_H

#include <memory>

#include "kraken/memory/buffer.h"
#include "kraken/adt/segment.h"
#include "kraken/lexer/token.h"
#include "kraken/support/error.h"

namespace lex {

class lexer {

    // \brief Buffer manager.
    std::unique_ptr<mem::buffer> buffer;

    // \brief The index where the lexer is reading.
    std::size_t index;

    template<class predicate>
    void move_while(predicate p) {
        while (p(this->get()))
            ++index;
    }

    inline wchar_t get() const noexcept {
        if (__builtin_expect(index >= buffer->size(), 0))
            return '\0';
        return buffer->get(index);
    }

    inline wchar_t *ptr() const noexcept {
        if (__builtin_expect(index >= buffer->size(), 0))
            return buffer->end();
        return buffer->begin() + index;
    }

    tok::token scan_integer() noexcept;
    tok::token scan_character_literal() noexcept;
    tok::token scan_string_literal() noexcept;
    tok::token scan_identifier() noexcept;

public:
    // ctor.
    lexer(std::unique_ptr<mem::buffer> bm);

    tok::token scan() noexcept;
};

} // namespace lex

#endif // KRAKEN_LEXER_LEXER_H
