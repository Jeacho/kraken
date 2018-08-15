
#include <gtest/gtest.h>

#include "kraken/support/console.h"

TEST(color_console, console_test) {
    std::cout << fg::black << "black foreground" << std::endl;
    std::cout << fg::red << "red foreground" << std::endl;
    std::cout << fg::green << "green foreground" << std::endl;
    std::cout << fg::yellow << "yellow foreground" << std::endl;
    std::cout << fg::blue << "blue foreground" << std::endl;
    std::cout << fg::magenta << "magenta foreground" << std::endl;
    std::cout << fg::cyan << "cyan foreground" << std::endl;
    std::cout << fg::white << "white foreground" << std::endl;
    std::cout << fg::white << bg::black << "black background" << reset << std::endl;
    std::cout << fg::white << bg::red << "red background" << reset << std::endl;
    std::cout << fg::white << bg::green << "green background" << reset << std::endl;
    std::cout << fg::white << bg::yellow << "yellow background" << reset << std::endl;
    std::cout << fg::white << bg::blue << "blue background" << reset << std::endl;
    std::cout << fg::white << bg::magenta << "magenta background" << reset << std::endl;
    std::cout << fg::white << bg::cyan << "cyan background" << reset << std::endl;
    std::cout << fg::black << bg::white << "white background" << reset << std::endl;
}
