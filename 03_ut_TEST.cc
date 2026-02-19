#include <gtest/gtest.h>
#include "classes.h"

// -> leave out
// Demonstrate some basic assertions.
TEST(SquareTestSuite, IsEmptyInitiallyTest) {
    Square Square;

    // expecting width and height to be initialized with 0
    EXPECT_EQ(Square.get_width(), 0);
    EXPECT_EQ(Square.get_height(), 0);

}

TEST(SquareTestSuite, setValuesCorrectlyTest) {
    int a = 1, b = 2;
    Square Square;
    
    // expect no error when setting values
    EXPECT_NO_THROW(Square.set_values(1, 2, "Square1"));

    // expect equality
    EXPECT_EQ(Square.get_width(), a);
    EXPECT_EQ(Square.get_height(), b);
  
}

TEST(SquareTestSuite, calculateAreaCorrectlyTest) {
    int a = 1, b = 4;
    Square Square;

    // expect no error when setting values
    EXPECT_NO_THROW(Square.set_values(a, b, "Square2"));

    // expect equality
    EXPECT_EQ(Square.get_area(), 12) << "The calculated area should be: " << a*b;

}