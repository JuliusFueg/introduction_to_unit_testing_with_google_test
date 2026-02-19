#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// Explicit Success and Failure:

TEST(explicitSuccessAndFailureTestSuite, SUCCEEDandFAIL_Test) {
    // define preconditions and expected results
    int a = 10, b = 5, expectedResult = 2, result = 0;

    // trigger function under test
    ASSERT_NO_THROW(result = divideTwoInts(a, b));

    // expecting width and height to be initialized with 0
    switch (result) {
    case 1:
        ADD_FAILURE() << "The result is wrong. Generates a nonfatal failure.";
        FAIL() << "The result is wrong. Generates a fatal failure.";
        break;
    case 2:
        SUCCEED() << "The result is correct. This test case succeeds.";
        break;
    default:
        ADD_FAILURE_AT("C:/Users/fgj/Documents/2_Projects/8_Presentations/20220515_gtest/gtest_presentation/ut_gtest.cc", 162);
        FAIL() << "The result is wrong. Generates a fatal failure.";
        break;
    }

}
