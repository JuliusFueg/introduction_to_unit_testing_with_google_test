#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// Boolean Conditions:
TEST(booleanConditionsTestSuite, EXPECTTRUEandEXPECTFALSETest) {
    int a = 10;

    EXPECT_TRUE(isIntEven(a)) << "Should be true.";

    EXPECT_FALSE(isIntEven(a)) << "Should be false.";
}