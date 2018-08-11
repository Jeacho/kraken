#ifndef KRAKEN_SUPPORT_CONSOLE_H
#define KRAKEN_SUPPORT_CONSOLE_H

#include <iostream>
#include <cstdio>

#include "kraken/support/compiler.h"

namespace cs {

std::ostream &reset(std::ostream &stream);

#if defined(MACOS) || defined(LINUX)
std::ostream &bold(std::ostream &stream);
std::ostream &dark(std::ostream &stream);
std::ostream &underline(std::ostream &stream);
std::ostream &blink(std::ostream &stream);
#endif

namespace fg {

// \brief Foreground colors
std::ostream &grey(std::ostream &stream);
std::ostream &red(std::ostream &stream);
std::ostream &green(std::ostream &stream);
std::ostream &yellow(std::ostream &stream);
std::ostream &blue(std::ostream &stream);
std::ostream &magenta(std::ostream &stream);
std::ostream &cyan(std::ostream &stream);
std::ostream &white(std::ostream &stream);

namespace br {

// \brief Bright foreground colors
std::ostream &grey(std::ostream &stream);
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

} // namesapce cs

#endif // KRAKEN_SUPPORT_CONSOLE_H
