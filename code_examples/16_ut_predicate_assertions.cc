#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// Predicate Assertions:
// Evaluate more complex predicates and printing more information than if only EXPECT_TRUE or EXPECT_FALSE was used alone

// Verifies that the predicate returns true when passed the given values as arguments.
TEST(predicateAssertionsTestSuite, EXPECTPRED1Test) {
    int numA = 4, numB = 5;

    // one input parameter
    EXPECT_PRED1(isIntEven, numA);
    EXPECT_PRED1(isIntEven, numB);

}

// Evaluate function with return type bool and two input parameters
TEST(predicateAssertionsTestSuite, EXPECTPRED2Test) {
    int numA = 4, numB = 5;

    // multiple input parameter
    EXPECT_PRED2(isIntSumEven, numA, numB);

}








//
//// ::testing::AssertionResult for more flexible assertions and error messages. 
//// It's possible to have error messages in case of success and failure.
//// An AssertionResult object represents the result of an assertion (success, failure, message)
//::testing::AssertionResult AssertIsIntEven(int n) {
//    if (isIntEven(n) == true)
//        return testing::AssertionSuccess() << n << " is even"; // Why isn't the success message printed?
//    else
//        return testing::AssertionFailure() << n << " is odd";
//}
//
//TEST(predicateAssertions_TestSuite, EXPECT_TRUE_Test) {
//    int numA = 4, numB = 5;
//
//    EXPECT_TRUE(AssertIsIntEven(numA));  // Succeeds
//    EXPECT_TRUE(AssertIsIntEven(numB));  // Fails
//}
//
//
//testing::AssertionResult AssertIsIntSumEven(const char* a_expr,
//                                            const char* b_expr,
//                                            int a,
//                                            int b) {
//
//    if (isIntSumEven(a, b) == true) {
//        return testing::AssertionSuccess() << "The sum of " << a_expr << " and " << b_expr
//            << " (" << a << " and " << b << ") is an even number."; // Returns an AssertionResult object to indicate that an assertion has succeeded
//    }
//    else {
//        return testing::AssertionFailure() << "The sum of " << a_expr << " and " << b_expr
//        << " (" << a << " and " << b << ") is not an even number."; // Returns an AssertionResult object to indicate that an assertion has failed
//    }
//}
//
//TEST(predicateAssertions_TestSuite, EXPECT_PRED_FORMAT2_Test) {
//    int numA = 4, numB = 5, numC = 5;
//
//    EXPECT_PRED_FORMAT2(AssertIsIntSumEven, numB, numC);  // Succeeds
//    EXPECT_PRED_FORMAT2(AssertIsIntSumEven, numA, numB);  // Fails
//}
//
//// Predicate assertions for floating point comparisons:
//using ::testing::FloatLE;
//
//TEST(predicateAssertions_TestSuite, EXPECT_PRED_FORMAT2_FloatLE_Test) {
//    float numA = 1.1, numB = 1.2;
//    EXPECT_PRED_FORMAT2(FloatLE, numA, numB);
//}
//
//using ::testing::DoubleLE;
//
//TEST(predicateAssertions_TestSuite, EXPECT_PRED_FORMAT2_DoubleLE_Test) {
//    double numA = 1.2, numB = 1.1;
//    EXPECT_PRED_FORMAT2(DoubleLE, numA, numB);
//}