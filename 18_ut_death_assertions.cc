#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// Death Assertions:
// Verifies if a piece of code causes the process to terminate with a non-zero exit status. 

/*
A death test cares about three things:

    does the statement abort or exit the process?
    does the exit status satisfy predicate?
    does the stderr output match matcher?
*/

TEST(deathAssertionsTestSuite, EXPECTDEATHTest) {
    int a = 1, b = 0;

    EXPECT_DEATH(zeroCheck(b), "The number is 0. Can't be used as divisor. "); // Verifies that statement causes the process to terminate with a nonzero exit status and produces stderr output that matches matcher

    EXPECT_EXIT(zeroCheck(a), ::testing::ExitedWithCode(0), ""); // calling zeroCheck() causes the process to print "" to stderr and exit with exit code 0

}















//// If a test fixture class is shared by normal tests and death tests, you can use using or typedef to introduce an alias for the fixture classand avoid duplicating its code.
//// Due to well - known problems with forking in the presence of threads, death tests should be run in a single - threaded context.Sometimes, however, it isn’t feasible to arrange that kind of environment.For example, statically - initialized modules may start threads before main is ever reached.Once threads have been created, it may be difficult or impossible to clean them up.
///*
//googletest has three features intended to raise awareness of threading issues.
//
//    A warning is emitted if multiple threads are running when a death test is encountered.
//    Test suites with a name ending in “DeathTest” are run before all other tests.
//    It uses clone() instead of fork() to spawn the child process on Linux (clone() is not available on Cygwin and Mac), as fork() is more likely to cause the child to hang when the parent process has multiple threads.
//
//It’s perfectly fine to create threads inside a death test statement; they are executed in a separate process and cannot affect the parent.
//*/
//
//
//class SquareTest_F : public testing::Test {
//protected:
//    int a = 1, b = 2, c = 3, d = 4;
//    void SetUp() override {
//        testSquare2.set_values(a, b,"testSquare2");
//        testSquare3.set_values(c, d,"testSquare3");
//    }
//    //void TearDown() override {}
//
//    Square testSquare1;
//    Square testSquare2;
//    Square testSquare3;
//};
//
//using Square_DeathTest = SquareTest_F; // here I take the test class SquareTest_F and use it also for DeathTest
//
//TEST_F(SquareTest_F, setValuesCorrectly) {
//    // normal test
//    EXPECT_EQ(testSquare2.get_width(), 1);
//    EXPECT_EQ(testSquare2.get_height(), 2);
//}
//
//TEST_F(Square_DeathTest, zerocheck_DeathTest) {
//    // death test
//    // GTEST_FLAG_SET(death_test_style, "threadsafe"); and GTEST_FLAG_SET(death_test_style, "fast");
//    // This test is run in the "threadsafe" style:
//    EXPECT_DEATH(testSquare2.get_width(), ""); // with "" it will succeed
//}
//
///* add:
//TEST(MyDeathTest, KillProcess) {
//    EXPECT_EXIT(KillProcess(), testing::KilledBySignal(SIGKILL), "Sending myself unblockable signal");
//}*/
//
///* The statement argument of ASSERT_EXIT() can be any valid C++ statement. If it leaves the current function via a return statement or by throwing an exception, the death test is considered to have failed. Some googletest macros may return from the current function (e.g. ASSERT_TRUE()), so be sure to avoid them in statement.
//
//Since statement runs in the child process, any in-memory side effect (e.g. modifying a variable, releasing memory, etc) it causes will not be observable in the parent process. In particular, if you release memory in a death test, your program will fail the heap check as the parent process will never see the memory reclaimed. To solve this problem, you can
//
//    try not to free memory in a death test;
//    free the memory again in the parent process; or
//    do not use the heap checker in your program.
//*/
//// Despite the improved thread safety afforded by the “threadsafe” style of death test, thread problems such as deadlock are still possible in the presence of handlers registered with pthread_atfork(3).