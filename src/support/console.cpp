
#include "kraken/support/console.h"

#include <iostream>
#include <cstdio>

#if defined(MACOS) || defined(LINUX)
# include <unistd.h>
#elif defined(WINDOWS)
# include <io.h>
# include <windows.h>
#endif

namespace detail {

static int colorize_index = std::ios_base::xalloc();

static constexpr FILE *get_stdstream(std::ostream &stream) noexcept {
    if (&stream == &std::cout)
        return stdout;
    else if ((&stream == &std::cerr) || (&stream == &std::clog))
        return stderr;

    return nullptr;
}

static bool is_atty(std::ostream &stream) {
    FILE *stdstream = get_stdstream(stream);

    if (!stdstream) return false;

#if defined(MACOS) || defined(LINUX)
    return ::isatty(fileno(stdstream))
        || static_cast<bool>(stream.iword(colorize_index));;
#elif defined(WINDOWS)
    return ::_isatty(_fileno(stdstream))
        || static_cast<bool>(stream.iword(colorize_index));;
#endif
}

#if defined(WINDOWS)

// \brief Sets the windows console's color attributes.
static void win32_atty(std::ostream &stream, int fg, int bg) {
    static WORD defaultAttributes = 0;

    if (!has_atty(stream))
        return;

    HANDLE hTerminal = INVALID_HANDLE_VALUE;
    if (&stream == &std::cout)
        hTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    else if (&stream == &std::cerr)
        hTerminal = GetStdHandle(STD_ERROR_HANDLE);

    if (!defaultAttributes) {
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (!GetConsoleScreenBufferInfo(hTerminal, &info))
            return;
        defaultAttributes = info.wAttributes;
    }

    if (fg == -1 && bg == -1) {
        SetConsoleTextAttribute(hTerminal, defaultAttributes);
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hTerminal, &info))
        return;

    if (fg != -1) {
        info.wAttributes &= ~(info.wAttributes & 0x0F);
        info.wAttributes |= static_cast<WORD>(fg);
    }

    if (bg != -1) {
        info.wAttributes &= ~(info.wAttributes & 0xF0);
        info.wAttributes |= static_cast<WORD>(bg);
    }

    SetConsoleTextAttribute(hTerminal, info.wAttributes);
}

#endif // WINDOWS

} // namespace detail

#if defined(MACOS) || defined(LINUX)
# define COLOR(name, ansi, win32_fg, win32_bg)                      \
std::ostream &name(std::ostream &stream) {                          \
    if (__builtin_expect(detail::is_atty(stream), 1))               \
        stream << "\033[" #ansi "m";                                \
    return stream;                                                  \
}
#elif defined(WINDOWS)
# define COLOR(name, ansi, win32_fg, win32_bg)                      \
std::ostream &name(std::ostream &stream) {                          \
    if (__builtin_expect(detail::is_atty(stream), 1))               \
        detail::win32_atty(stream, win32_fg, win32_bg);             \
    return stream;                                                  \
}
#elif
# define COLOR
#endif

#define FG_COLOR(name, ansi, win32_fg) \
    COLOR(name, ansi, win32_fg, -1)

#define BG_COLOR(name, ansi, win32_bg) \
    COLOR(name, ansi, -1, win32_bg)

COLOR(reset, 00, -1, 01)

std::ostream &bold(std::ostream &stream) {
    if (__builtin_expect(detail::is_atty(stream), 1))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[1m";
#endif
    return stream;
}

std::ostream &dark(std::ostream &stream);
std::ostream &underline(std::ostream &stream);
std::ostream &blink(std::ostream &stream);

namespace fg {

FG_COLOR(black,     30, 0);
FG_COLOR(red,       31, FOREGROUND_RED)
FG_COLOR(green,     32, FOREGROUND_GREEN)
FG_COLOR(yellow,    33, FOREGROUND_GREEN | FOREGROUND_RED)
FG_COLOR(blue,      34, FOREGROUND_BLUE)
FG_COLOR(magenta,   35, FOREGROUND_BLUE | FOREGROUND_RED)
FG_COLOR(cyan,      36, FOREGROUND_BLUE | FOREGROUND_GREEN)
FG_COLOR(white,     37, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)

namespace br {

FG_COLOR(black,     90, FOREGROUND_INTENSITY);
FG_COLOR(red,       91, FOREGROUND_INTENSITY | FOREGROUND_RED)
FG_COLOR(green,     92, FOREGROUND_INTENSITY | FOREGROUND_GREEN)
FG_COLOR(yellow,    93, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED)
FG_COLOR(blue,      94, FOREGROUND_INTENSITY | FOREGROUND_BLUE)
FG_COLOR(magenta,   95, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED)
FG_COLOR(cyan,      96, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN)
FG_COLOR(white,     97, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)

} // namesapce br

} // namespace fg

namespace bg {

BG_COLOR(black,     40, 0);
BG_COLOR(red,       41, FOREGROUND_RED)
BG_COLOR(green,     42, FOREGROUND_GREEN)
BG_COLOR(yellow,    43, FOREGROUND_GREEN | FOREGROUND_RED)
BG_COLOR(blue,      44, FOREGROUND_BLUE)
BG_COLOR(magenta,   45, FOREGROUND_BLUE | FOREGROUND_RED)
BG_COLOR(cyan,      46, FOREGROUND_BLUE | FOREGROUND_GREEN)
BG_COLOR(white,     47, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)

namespace br {

BG_COLOR(black,     100, FOREGROUND_INTENSITY);
BG_COLOR(red,       101, FOREGROUND_INTENSITY | FOREGROUND_RED)
BG_COLOR(green,     102, FOREGROUND_INTENSITY | FOREGROUND_GREEN)
BG_COLOR(yellow,    103, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED)
BG_COLOR(blue,      104, FOREGROUND_INTENSITY | FOREGROUND_BLUE)
BG_COLOR(magenta,   105, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED)
BG_COLOR(cyan,      106, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN)
BG_COLOR(white,     107, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)

} // namesapce br

} // namespace bg
