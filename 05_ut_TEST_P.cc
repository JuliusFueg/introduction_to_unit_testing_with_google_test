#include <gtest/gtest.h>
#include "classes.h"

// -> leave out
/* parameterized testing with one variable */
class SquareOneVariableTEST_P : public ::testing::TestWithParam<int> {
protected:
    int widthParam;
};

TEST_P(SquareOneVariableTEST_P, handlingOfWidthInRange) {
    int width = GetParam();
    int height = 10;

    Square testSquare1(width, height, "testSquare1");
    EXPECT_EQ(testSquare1.get_width(), GetParam());
    EXPECT_EQ(testSquare1.get_height(), 10);

}

INSTANTIATE_TEST_CASE_P(valuesTEST_P, SquareOneVariableTEST_P,
    ::testing::Values(-5, 3, 97, 1000, 4003)); /* width */

INSTANTIATE_TEST_CASE_P(rangeTEST_P, SquareOneVariableTEST_P,
    ::testing::Range(-100, 100, 10)); /* width */

/* parameterized testing with multiple variables and tuples */
class SquareMultipleVariablesTEST_P : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:
    int widthParam;
    int heightParam;
};

TEST_P(SquareMultipleVariablesTEST_P, handlingOfParametersInRange) {
    int width = std::get<0>(GetParam());
    int height = std::get<1>(GetParam());

    Square testSquare1(width, height,"testSquare1");
    EXPECT_EQ(testSquare1.get_width(), std::get<0>(GetParam()));
    EXPECT_EQ(testSquare1.get_height(), std::get<1>(GetParam()));

}

INSTANTIATE_TEST_CASE_P(tupleTEST_P, SquareMultipleVariablesTEST_P,
    ::testing::Values(std::make_tuple(1, 3), /* width, height */
                      std::make_tuple(7, 37))); /* width, height */

INSTANTIATE_TEST_CASE_P(combineRangeTEST_P, SquareMultipleVariablesTEST_P,
    ::testing::Combine(::testing::Range(-100, 100, 10),  /* width */
                       ::testing::Range(-100, 100, 10))); /* height */

INSTANTIATE_TEST_CASE_P(combineRangeAndValuesTEST_P, SquareMultipleVariablesTEST_P,
    ::testing::Combine(::testing::Values(3, 37),  /* width */
                       ::testing::Range(-100, 100, 10))); /* height */


