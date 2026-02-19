#include "gmock/gmock.h"
#include "classes.h"
#include "functions.h"

//using ::testing::AllOf;
using ::testing::Gt;
using ::testing::Lt;

// Generalized Assertion:
TEST(generalizedAssertionTestSuite, GtLtTest) {
    int a = 1, b = 2;

    EXPECT_THAT(b, Gt(a));
    EXPECT_THAT(a, Lt(b));
}

// String assertions using gMock string matchers
using ::testing::HasSubstr;
TEST(generalizedAssertionTestSuite, HasSubstrTest) {
    char searchString[] = "Let's look for the needle in the hay.";

    EXPECT_THAT(searchString, HasSubstr("needle"));
}

using ::testing::MatchesRegex;
TEST(generalizedAssertionTestSuite, MatchesRegexTest) {
    char searchString[] = "Let's look for the needle in the hay.";

    EXPECT_THAT(searchString, MatchesRegex("Let's look for the needle in the hay."));
}

using ::testing::StartsWith;
TEST(generalizedAssertionTestSuite, StartsWithTest) {
    char searchString[] = "Let's look for the needle in the hay.";

    EXPECT_THAT(searchString, StartsWith("Let's"));
}

// String Comparison: Compare two C style strings. To compare two string objects, use EXPECT_EQ or EXPECT_NE instead.

TEST(stringComparisonTestSuite, STRcompTest) {
    char nameA[] = "Hans";
    char upperCaseNameA[] = "HANS";
    char nameB[] = "Hans";
    char nameC[] = "Christina";
    char upperCaseNameC[] = "CHRISTINA";

    /* STREQ, STRNE */
    EXPECT_STREQ(nameA, nameB);
    EXPECT_STRNE(nameA, nameC);

    /* STRCASEEQ, STRCASENE: ignoring case */
    EXPECT_STRCASEEQ(nameA, upperCaseNameA);
    EXPECT_STRCASENE(upperCaseNameA, upperCaseNameC);

    /* string objects */
    std::string stringNameA = "Nina";
    std::string stringNameB = "Markus";
    EXPECT_NE(stringNameA, stringNameB);

}