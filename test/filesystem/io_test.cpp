#include <gtest/gtest.h>

#include "kraken/filesystem/io.h"

TEST(read_utf8, io_test) {
    either<std::error_code, std::unique_ptr<mem::buffer>> directory
        = fs::read_utf8("C:/Users/jake/Desktop/kraken/samples/");
    ASSERT_EQ(directory.is_left(), TRUE);
    ASSERT_EQ(*directory.left(), std::errc::is_a_directory);

    either<std::error_code, std::unique_ptr<mem::buffer>> file
        = fs::read_utf8("C:/Users/jake/Desktop/kraken/samples/test/utf8-file.kkn");
    ASSERT_EQ(file.is_right(), TRUE);
}
