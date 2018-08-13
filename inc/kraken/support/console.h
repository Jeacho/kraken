#ifndef KRAKEN_SUPPORT_CONSOLE_H
#define KRAKEN_SUPPORT_CONSOLE_H

#include <iostream>
#include <cstdio>

#include "kraken/support/compiler.h"

namespace detail {

    // \brief Returns the FILE * to the standard stream; however, if a standard
    // stream is not provided it returns nullptr.
    static constexpr FILE *get_stdstream(std::ostream &stream) noexcept;

    // \brief Returns if the stream provided refers to a terminal.
    static bool has_atty(std::ostream &stream);

#if defined(WINDOWS)
    // \brief Special win32 implementation for changing terminal attributes.
    static void win32_atty(std::ostream &stream, int fg, int bg);
#endif

} // namespace detail

std::ostream &reset(std::ostream &stream);
std::ostream &bold(std::ostream &stream);
std::ostream &dark(std::ostream &stream);
std::ostream &underline(std::ostream &stream);
std::ostream &blink(std::ostream &stream);

namespace fg {

// \brief Foreground colors
std::ostream &black(std::ostream &stream);
std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);
std::ostream &white(std::ostream &stream);

namespace br {

// \brief Bright foreground colors
std::ostream &black(std::ostream &stream);
std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);
std::ostream &white(std::ostream &stream);

} // namesapce br

} // namespace fg

namespace bg {

// \brief Background colors
std::ostream &black(std::ostream &stream);
std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);
std::ostream &white(std::ostream &stream);

namespace br {

// \brief Bright background colors
std::ostream &black(std::ostream &stream);
std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);
std::ostream &white(std::ostream &stream);

} // namesapce br

} // namespace bg

#endif // KRAKEN_SUPPORT_CONSOLE_H
