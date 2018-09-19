#ifndef KRAKEN_LEXER_TYPES_H
#define KRAKEN_LEXER_TYPES_H

#include <iostream>

namespace tok {

enum class type {
    error,          // bad token
    end_of_file,    // end of file

    identifier,

    integer_literal,
    floating_literal,
    character_literal,
    string_literal,
};

} // namespace tok

template<class char_type, class traits>
std::basic_ostream<char_type, traits> &
operator<<(std::basic_ostream<char_type, traits> &os, tok::type t) {
    switch (t) {
    case tok::type::error:              return os << L"error";
    case tok::type::end_of_file:        return os << L"end_of_file";
    case tok::type::integer_literal:    return os << L"integer_literal";
    case tok::type::floating_literal:   return os << L"floating_literal";
    case tok::type::character_literal:  return os << L"character_literal";
    case tok::type::string_literal:     return os << L"string_literal";
    case tok::type::identifier:         return os << L"identifier";
    default:
        return os << "<>";
    }
}

#endif // KRAKEN_LEXER_TYPES_H
