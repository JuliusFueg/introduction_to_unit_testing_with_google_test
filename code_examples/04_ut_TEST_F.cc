#include <gtest/gtest.h>
#include "classes.h"

/* test fixture testing */
class SquareTestF : public ::testing::Test {
protected:

    // define preconditions and expected results
    int a = 1, b = 2, c = 3, d = 4;

    void SetUp() override {
        testSquare2.set_values(a, b);
        testSquare3.set_values(c, d);
    }
    //void TearDown() override {}

    Square testSquare1;
    Square testSquare2;
    Square testSquare3;
};

TEST_F(SquareTestF, IsEmptyInitially) {
    EXPECT_EQ(testSquare1.get_width(), 0);
    EXPECT_EQ(testSquare1.get_height(), 0);
}

TEST_F(SquareTestF, setValuesCorrectly) {
    EXPECT_EQ(testSquare2.get_width(), 1);
    EXPECT_EQ(testSquare2.get_height(), 2);
}

TEST_F(SquareTestF, calculateAreaulatedCorrectly) {
    EXPECT_EQ(testSquare3.get_area(), 12);
}
