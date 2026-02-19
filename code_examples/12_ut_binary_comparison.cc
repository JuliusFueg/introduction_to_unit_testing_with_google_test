#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// Binary Comparison:

TEST(binaryComparison_TestSuite, EQ_NE_Test) {
    int a = 3, b = 4;
    Square SquareA(a,b,"SquareA");
    Square* ptr = NULL;
    ASSERT_EQ(ptr, nullptr);
    ptr = &SquareA;

    SquareA.calculateArea();

    /* EQ */
    EXPECT_EQ(SquareA.get_area(), a*b) << "EXPECT generates nonfatal failures and allow the current function to continue running";
    ASSERT_EQ(SquareA.get_area(), a*b) << "ASSERT generates fatal failures and abort the current function";
    EXPECT_EQ(ptr, &SquareA) << "ptr points to adress of SquareA.";

    /* NE */
    EXPECT_NE(SquareA.get_area(), 0);
    ASSERT_NE(SquareA.get_area(), 0);
    ASSERT_NE(ptr, nullptr) << "ptr points to adress of SquareA.";

    /* LT, LE, GT, GE */
    EXPECT_LT(SquareA.get_area(), 2*a*b);
    EXPECT_LE(SquareA.get_area(), a*b);
    EXPECT_GT(SquareA.get_area(), a * b / 2);
    EXPECT_GE(SquareA.get_area(), a * b);

}