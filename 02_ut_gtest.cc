#include <gtest/gtest.h>
#include "functions.h"

// TEST macro
TEST(divideTwoIntsTestSuite, expectEqTest) {

  // define preconditions and expected results
  int a = 10, b = 5, expectedResult = 2, result;

  // trigger function under test
  ASSERT_NO_THROW(result = divideTwoInts(a, b));

  // define postconditions and evaluate results
  // ASSERT macro vs.EXPECT macro with EQ:
  EXPECT_EQ(result, expectedResult) << "EXPECT generates nonfatal failures and allows the current function to continue running. The sum should be: " << expectedResult;
  ASSERT_EQ(result, expectedResult) << "ASSERT generates fatal failures and aborts the current function";
}

TEST(divideTwoIntsTestSuite, moreComparisonsTest) {

    //GTEST_SKIP() << "Skipping single test";

    // define preconditions and expected results
    int a = 10, b = 2, expectedResult = 5, result;

    // trigger function under test
    EXPECT_NO_THROW(result = divideTwoInts(a, b));

    // relational macros: LT, LE, GT, GE
    EXPECT_LT(result, 10);
    EXPECT_LE(result, 5);
    EXPECT_GT(result, 0);
    EXPECT_GE(result, 5);

    // NE
    EXPECT_NE(result, 1000);
    ASSERT_NE(result, 1000);
}

// TEST_P macro
class divideTwoIntsTestSuiteValidParamsTESTP : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:
    //int intA=0;
    //int intB=0;
};

TEST_P(divideTwoIntsTestSuiteValidParamsTESTP, handlingOfValidParameters) {
    int a = std::get<0>(GetParam());
    int b = std::get<1>(GetParam());
    int result;
    int expectedResult = std::get<0>(GetParam()) / std::get<1>(GetParam());

    // trigger function under test
    ASSERT_NO_THROW(result = divideTwoInts(a, b));

    // define postconditions and evaluate results
    EXPECT_EQ(expectedResult, result);
}

INSTANTIATE_TEST_SUITE_P(tupleTESTP, divideTwoIntsTestSuiteValidParamsTESTP,
    ::testing::Values(  std::make_tuple(8, 4), /* first test case: a, b */
                        std::make_tuple(16, 4))); /* second test case: a, b */

INSTANTIATE_TEST_SUITE_P(combineRangeTESTP, divideTwoIntsTestSuiteValidParamsTESTP,
    ::testing::Combine( ::testing::Range(1, 100, 10),  /* a */
                        ::testing::Range(-100, -1, 10))); /* b */

INSTANTIATE_TEST_SUITE_P(combineRangeAndValuesTESTP, divideTwoIntsTestSuiteValidParamsTESTP,
    ::testing::Combine( ::testing::Range(1, 100, 10),  /* a */
                        ::testing::Values(5, 10))); /* b */

class divideTwoIntsTestSuiteInvalidParamsTESTP : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:
    int intA = 0;
    int intB = 0;
};

TEST_P(divideTwoIntsTestSuiteInvalidParamsTESTP, handlingOfInvalidParameters) {
    int a = std::get<0>(GetParam());
    int b = std::get<1>(GetParam());
    int result;

    // trigger function under test
    EXPECT_THROW(result = divideTwoInts(a, b), std::invalid_argument) << "Function should throw here.";
    //ASSERT_THROW(result = divideTwoInts(a, b), std::invalid_argument) << "Function should throw here.";
    EXPECT_ANY_THROW(result = divideTwoInts(a, b));
}

INSTANTIATE_TEST_SUITE_P(invalidRangeTEST_P, divideTwoIntsTestSuiteInvalidParamsTESTP,
    ::testing::Combine(::testing::Range(1, 100, 10),  /* a */
                        ::testing::Values(0) )); /* b -> 0 is always invalid */

// TEST_F macro
class divideTwoIntsTestSuiteTESTF : public ::testing::Test {
protected:
    // define preconditions and expected results
    int a = 10, b = 5, c = 8, d = 2, result = 0;

    void SetUp() override {
        GTEST_SKIP() << "Skipping all tests for this fixture";
    }

    //void TearDown() override {}
};

// Tests for SkipFixture won't be executed.
TEST_F(divideTwoIntsTestSuiteTESTF, addTest1) {

    // trigger function under test
    ASSERT_NO_THROW(result = divideTwoInts(a, b)); 
    EXPECT_EQ(result, a/b);
}

TEST_F(divideTwoIntsTestSuiteTESTF, addTest2) {

    // trigger function under test
    ASSERT_NO_THROW(result = divideTwoInts(c, d));
    EXPECT_EQ(result, c/d);
}

///*
//When this test runs, the following happens :
//
//1. googletest constructs a divideTwoIntsTestSuiteTEST_F object (let’s call it t1)
//2. t1.SetUp() initializes t1
//3. The first test (addTest1) runs on t1
//4. t1.TearDown() cleans up after the test finishes
//5. t1 is destructed
//6. The above steps are repeated on another divideTwoIntsTestSuiteTEST_F object, this time running the addTest2 test
//*/
//
///*
//Why should I prefer test fixtures over global variables?
//
//1. It’s likely that a test needs to change the states of its global variables. 
//   This makes it difficult to keep side effects from escaping one test and contaminating others, making debugging difficult. 
//   By using fixtures, each test has a fresh set of variables that’s different (but with the same names). Thus, tests are kept independent of each other.
//2. Global variables pollute the global namespace
//3. Test fixtures can be reused via subclassing, which cannot be done easily with global variables. This is useful if many test suites have something in common.
//*/
//
