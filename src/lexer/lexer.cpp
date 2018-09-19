
#include "kraken/lexer/lexer.h"

using namespace lex;

lexer::lexer(std::unique_ptr<mem::buffer> bm) : buffer(std::move(bm)) {
    index = 0;
}

tok::token lexer::scan_integer() noexcept {
    assert(std::iswdigit(this->get())
        && "lexer::scan_integer started on a integer.");

    tok::type kind = tok::type::integer_literal;
    wchar_t *begin = this->ptr();

scan_jump:
    move_while(std::iswdigit);

    switch(this->get()) {
    case L'.':
        ++index;

        if (kind == tok::type::floating_literal) {
            std::cerr << "noooooooo two danimals and thats no good" << '\n';
            move_while(std::iswdigit);
            return tok::token(tok::type::error,
                wsegment(begin, std::size_t(this->ptr() - begin)));
        }

        kind = tok::type::floating_literal;
        goto scan_jump;

    case L'F':
    case L'f':
        kind = tok::type::floating_literal;
        ++index;
        break;
    }

    return tok::token(kind, wsegment(begin, std::size_t(this->ptr() - begin)));
}

tok::token lexer::scan_character_literal() noexcept {
    assert(this->get() == L'\''
        && "lexer::scan_character_literal not started on a \'");

    ++index;
    wchar_t *ch = this->ptr();

    move_while([] (wchar_t c) -> bool {
        return c != L'\'' && c != L'\0' && c != L'\n';
    });

    if (this->get() == L'\n' || this->get() == '\0') {
        std::cerr << "woaah nelly, you didnt terminate your character literal" << std::endl;
        return tok::token(tok::type::error,
            wsegment(ch, std::size_t(this->ptr() - ch)));
    }

    if (std::ptrdiff_t(this->ptr() - ch) == 0) {
        std::cerr << "hey uhh... ur character literal emtpy af my dude ://" << std::endl;
        return tok::token(tok::type::error, wsegment(ch, 1));
    }

    if (std::ptrdiff_t(this->ptr() - ch) > 1) {
        std::cerr << "hey just a heads up, im gonna ignore all this extraness buddy" << std::endl;
    }

    ++index;

    return tok::token(tok::type::character_literal, wsegment(ch, 1));
}

tok::token lexer::scan_string_literal() noexcept {
    assert(this->get() == L'\"'
        && "lexer::scan_character_literal not started on a \"");

    ++index;
    wchar_t *begin = this->ptr();

    move_while([] (wchar_t c) -> bool {
        return c != L'\"' && c != L'\0' && c != L'\n';
    });

    if (this->get() == L'\n' || this->get() == L'\0') {
        std::cerr << "woaah nelly, you didnt terminate your string literal" << std::endl;
        return tok::token(tok::type::error,
            wsegment(begin, std::size_t(this->ptr() - begin)));
    }

    ++index;

    return tok::token(tok::type::string_literal,
        wsegment(begin, std::size_t(this->ptr() - begin - 1)));
}

tok::token lexer::scan_identifier() noexcept {
    assert(std::iswalpha(this->get()) || this->get() == L'_'
        && "lexer::scan_identifier not started on a alpha-numeric character or '_'");

    wchar_t *begin = this->ptr();

    move_while([] (wchar_t c) -> bool {
        return std::iswalnum(c) || c == '_';
    });

    return tok::token(tok::type::identifier,
        wsegment(begin, std::size_t(this->ptr() - begin)));
}

tok::token lexer::scan() noexcept {
    move_while(std::iswspace);

    if (__builtin_expect(this->get() == L'\0', 0))
        return tok::token(tok::type::string_literal, wsegment(this->ptr(), 1));

    switch (this->get()) {
    case L'\'':
        return scan_character_literal();

    case L'\"':
        return scan_string_literal();

    case L'1': case L'2': case L'3':
    case L'4': case L'5': case L'6':
    case L'7': case L'8': case L'9':
    case L'0':
        return scan_integer();
        
    default:
        if (std::iswalpha(this->get()) || this->get() == '_')
            return scan_identifier();
    }
}
