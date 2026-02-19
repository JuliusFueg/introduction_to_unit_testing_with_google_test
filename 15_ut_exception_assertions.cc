#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"

// Exception Assertions:

TEST(exceptionAssertions_TestSuite, EXPECT_THROWS_Test) {
    Square SquareA;

    EXPECT_THROW(SquareA.set_values(101, 200, "SquareA"), std::bad_alloc) << "This isn't the exception type that we are expecting.";
    EXPECT_THROW(SquareA.set_values(101, 200, "SquareA"), std::range_error);

    EXPECT_ANY_THROW(SquareA.set_values(101, 200, "SquareA"));
    EXPECT_NO_THROW(SquareA.set_values(99, -1, "SquareA"));

    /* alternative */
    try {
        SquareA.set_values(101, 200, "SquareA");
    }
    catch (std::exception& e) {
        std::cerr << "exception caught: " << e.what() << '\n';
        FAIL();
    }

}