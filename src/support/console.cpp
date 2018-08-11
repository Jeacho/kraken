
#include "kraken/support/console.h"

#include <iostream>
#include <cstdio>

#if defined(MACOS) || defined(LINUX)
# include <unistd.h>
#elif defined(WINDOWS)
# include <io.h>
# include <windows.h>
#endif

static int colorize_index = std::ios_base::xalloc();

static FILE *get_stdstream(const std::ostream &stream) noexcept {
    if (&stream == &std::cout)
        return stdout;
    else if ((&stream == &std::cerr) || (&stream == &std::clog))
        return stderr;

    return nullptr;
}

static bool has_atty(const std::ostream &stream) {
    FILE *stdstream = get_stdstream(stream);

    if (!stdstream) return false;

#if defined(MACOS) || defined(LINUX)
    return ::isatty(fileno(stdstream));
#elif defined(WINDOWS)
    return ::_isatty(_fileno(stdstream));
#endif
}

static inline bool is_colorized(std::ostream &stream) {
   return has_atty(stream) || static_cast<bool>(stream.iword(colorize_index));
}

#if defined(WINDOWS)

// \brief Sets the windows console's color attributes.
static void win_set_atty(std::ostream &stream, int fg, int bg) {
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

std::ostream &reset(std::ostream &stream);

#if defined(MACOS) || defined(LINUX)
std::ostream &bold(std::ostream &stream);
std::ostream &dark(std::ostream &stream);
std::ostream &underline(std::ostream &stream);
std::ostream &blink(std::ostream &stream);
#endif

namespace fg {

// \brief Foreground colors
std::ostream &grey(std::ostream &stream) {
    if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[40m";
#elif defined(WINDOWS)
        win_set_atty(stream, 8, 0);
#endif
    return stream;
}

std::ostream &red(std::ostream &stream) {
   if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
       stream << "\033[31m";
#elif defined(WINDOWS)
       win_set_atty(stream, 4, 0);
#endif
   return stream;
}

std::ostream &green(std::ostream &stream) {
   if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
       stream << "\033[31m";
#elif defined(WINDOWS)
       win_set_atty(stream, 4, 0);
#endif
   return stream;
}

std::ostream &yellow(std::ostream &stream) {
    if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[33m";
#elif defined(WINDOWS)
        win_set_atty(stream, FG_GREEN | FG_RED);
#endif
    return stream;
}

std::ostream &blue(std::ostream &stream) {
    if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[34m";
#elif defined(WINDOWS)
        win_set_atty(stream, FG_BLUE);
#endif
    return stream;
}

std::ostream &magenta(std::ostream &stream) {
    if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[35m";
#elif defined(WINDOWS)
        win_set_atty(stream, FG_BLUE | FG_RED);
#endif
    return stream;
}

std::ostream &cyan(std::ostream &stream) {
    if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[36m";
#elif defined(WINDOWS)
        win_set_atty(stream, FG_BLUE | FG_GREEN);
#endif
    return stream;
}

std::ostream &white(std::ostream &stream) {
   if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
       stream << "\033[37m";
#elif defined(WINDOWS)
       win_set_atty(stream, 15, 0);
#endif
   return stream;
}

namespace br {

std::ostream &grey(std::ostream &stream) {
    if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[90m";
#elif defined(WINDOWS)
        win_set_atty(stream, 0   /* grey */);
#endif
    return stream;
}

std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);

std::ostream &white(std::ostream &stream) {
    if (is_colorized(stream))
#if defined(MACOS) || defined(LINUX)
        stream << "\033[97m";
#elif defined(WINDOWS)
        win_set_atty(stream, FG_BLUE | FG_GREEN | FG_RED);
#endif
    return stream;
}

} // namesapce br

} // namespace fg

namespace bg {

// \brief Background colors
std::ostream &grey(std::ostream &stream);
std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);
std::ostream &white(std::ostream &stream);

namespace br {

// \brief Bright background colors
std::ostream &grey(std::ostream &stream);
std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);
std::ostream &white(std::ostream &stream);

} // namesapce br

} // namespace bg
