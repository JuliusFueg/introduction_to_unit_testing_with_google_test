#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// String Comparison: Compare two C strings. To compare two string objects, use EXPECT_EQ or EXPECT_NE instead.

TEST(stringComparison_TestSuite, STRcomp_Test) {
    char nameA[] = "Hans";
    char upperCaseNameA[] = "HANS";
    char nameB[] = "Christina";
    char upperCaseNameB[] = "CHRISTINA";
    
    Square SquareA;
    SquareA.set_name(nameA);

    /* STREQ, STRNE */
    EXPECT_STREQ(SquareA.get_name(), nameA);
    EXPECT_STRNE(nameA, nameB);

    /* STRCASEEQ, STRCASENE: ignoring case */
    EXPECT_STREQ(nameA, upperCaseNameA);
    EXPECT_STRCASEEQ(nameA, upperCaseNameA);
    EXPECT_STRCASENE(upperCaseNameA, upperCaseNameB);

    /* string objects */
    std::string stringNameA = "Nina";
    std::string stringNameB = "Markus";
    EXPECT_NE(stringNameA, stringNameB);

}