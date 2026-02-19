#include <gtest/gtest.h>
#include "classes.h"
#include "functions.h"


// Typed test:
template <typename T>
class SquareTest : public testing::Test {
public:
    T a = 1, b = 2, c = 3, d = 4;
    void SetUp() override {
        testSquare2.set_values(a, b, "testSquare2");
        testSquare3.set_values(c, d, "testSquare3");
    }
    //void TearDown() override {}

    Square testSquare1;
    Square testSquare2;
    Square testSquare3;
};

using testTypes = ::testing::Types<int, unsigned int, float, double, char>;
TYPED_TEST_SUITE(SquareTest, testTypes);

TYPED_TEST(SquareTest, setValuesCorrectly) {
    EXPECT_EQ(testSquare2.get_width(), 1);
    EXPECT_EQ(testSquare2.get_height(), 2);
};

/* parameterized typed test */
template<typename T>
class AddOneTestsFixture : public ::testing::Test {

};
TYPED_TEST_SUITE_P(AddOneTestsFixture);

TYPED_TEST_P(AddOneTestsFixture, doAddOne) {
    ASSERT_EQ(5/*addOne(5)*/, 6) << "addOne(5) != 6!";
}

REGISTER_TYPED_TEST_SUITE_P(AddOneTestsFixture, doAddOne);

//using Types = testing::Types<int, long long, std::size_t>;
INSTANTIATE_TYPED_TEST_SUITE_P(TestPrefix, AddOneTestsFixture, testTypes);

// Type assertions
TEST(typeTest_TestSuite, StaticAssertTypeEq_intVsInt_Test) {
    ::testing::StaticAssertTypeEq<int, int> ();
};

TEST(typeTest_TestSuite, StaticAssertTypeEq_intVsFloat_Test) {
    ::testing::StaticAssertTypeEq<int, float>(); // If the types are different, the function call will fail to compile, the compiler error message will say that T1 and T2 are not the same type
};
