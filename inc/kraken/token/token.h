#ifndef KRAKEN_TOKEN_TOKEN_H
#define KRAKEN_TOKEN_TOKEN_H

#include "kraken/token/types.h"

namespace tok {

class token {
    // \brief The flavor of token this is.
    const type kind;

    // \brief This tokens lexeme.
    wchar_t *m_begin,
            *m_end;

public:
    token(type k) : kind(k) { /* pass */ }
};

} // namespace tok

#endif // KRAKEN_TOKEN_TOKEN_H
