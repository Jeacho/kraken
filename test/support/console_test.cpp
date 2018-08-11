
#include <gtest/gtest.h>

#include "kraken/support/console.h"

TEST(color_console, console_test) {
    std::cout << fg::red << "peepee" << std::endl;
    std::cout << fg::grey << ":o" << std::endl;
}
