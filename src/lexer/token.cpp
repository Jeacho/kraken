
#include "kraken/lexer/token.h"

std::wostream &operator<<(std::wostream &os, const tok::token &t) {
    return os << t.kind() << ':' << t.lexeme();
}
