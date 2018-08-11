#ifndef KRAKEN_TOKEN_TYPES_H
#define KRAKEN_TOKEN_TYPES_H

namespace tok {

enum class type {
    no_type,       // default token in lexer state

    end_of_file,    // end of file

    integer_literal,
    floating_literal,
};

} // namespace tok

#endif // KRAKEN_TOKEN_TYPES_H
