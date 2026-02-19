#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// -> leave out
/* ASSERT macro vs.EXPECT macro : */

/* ASSERT */
TEST(addTwoInts_TestSuite, ASSERT_EQ_Test) {
    int a=1, b=2, c=4, d;

    d = addTwoInts(a, b);

    /* assert equality */
    ASSERT_EQ(d, c) << "ASSERT generates fatal failures and abort the current function";

    /* expect equality */
    EXPECT_EQ(d, c) << "EXPECT generates nonfatal failures and allow the current function to continue running";

}

/* EXPECT */
TEST(addTwoInts_TestSuite, EXPECT_EQ_Test) {
  int a=1, b=2, c=4, d;

  d = addTwoInts(a, b);

  /* expect equality */
  EXPECT_EQ(d, c) << "EXPECT generates nonfatal failures and allow the current function to continue running";

  /* assert equality */
  ASSERT_EQ(d, c) << "ASSERT generates fatal failures and abort the current function";
  
}

