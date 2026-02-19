#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// Floating-Point Comparison: Avoid problems caused by rounding.

TEST(floatingPointComparisonTestSuite, EQTEST) {
    float a = 1.234, b = 2.345;
    double c = 3.456, d = 4.567;

    EXPECT_FLOAT_EQ(divideTwoFloats(a,b), a/b) << "Identical within 4 ULPs (Units in the Last Place) from each other";
    ASSERT_FLOAT_EQ(divideTwoFloats(a, b), a/b);

    EXPECT_DOUBLE_EQ(divideTwoDoubles(c, d), c/d) << "Identical within 4 ULPs (Units in the Last Place) from each other";
    ASSERT_DOUBLE_EQ(divideTwoDoubles(c, d), c/d);

    EXPECT_NEAR(divideTwoFloats(a, b), a/b, 0.1); // Verifies that the difference between val1 and val2 does not exceed the absolute error bound abs_error.
    ASSERT_NEAR(divideTwoFloats(a, b), a/b, 0.1);
}
