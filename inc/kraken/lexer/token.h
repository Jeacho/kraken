#ifndef KRAKEN_LEXER_TOKEN_H
#define KRAKEN_LEXER_TOKEN_H

#include "kraken/lexer/types.h"
#include "kraken/adt/segment.h"

namespace tok {

class token {
    // \brief The flavor of token this is.
    type m_kind;

    // \brief This tokens lexeme.
    wsegment m_lexeme;

public:
    token(type k, wsegment l)
         : m_kind(k), m_lexeme(l) { /* pass */ }

    token operator=(const token &other) {
        return token(other.kind(), other.lexeme());
    }

    type kind() const noexcept { return m_kind; }
    wsegment lexeme() const noexcept { return m_lexeme; }
};

} // namespace tok

std::wostream &operator<<(std::wostream &os, const tok::token &t);

#endif // KRAKEN_LEXER_TOKEN_H
