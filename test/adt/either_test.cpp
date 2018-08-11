
#include <gtest/gtest.h>

#include <memory>

#include "kraken/adt/either.h"
#include "kraken/memory/buffer.h"

double unsafe_division(double q, double d) {
    if (d == 0.0f)
        throw std::domain_error("Divisor cannot be 0.");
    return q / d;
}

TEST(constructor, either_test) {
    // primitive types
    either<float, int> p_either = 5;
    ASSERT_EQ(p_either.is_right(), true);
    ASSERT_EQ(*p_either.right(), 5);

    // exception handling
    either<std::domain_error, double> e_either
         = attempt<std::domain_error>(unsafe_division, 2.0f, 0.0f);
    ASSERT_EQ(e_either.is_left(), true);
    ASSERT_STREQ(e_either.left()->what(), "Divisor cannot be 0.");

    // unique_ptr
    either<std::error_code, std::unique_ptr<mem::buffer>> up_either
         = std::unique_ptr<mem::buffer>(new mem::buffer(100));
    ASSERT_EQ(up_either.is_right(), true);
}
