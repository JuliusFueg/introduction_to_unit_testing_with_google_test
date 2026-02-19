#include <gtest/gtest.h>
#include "classes.h"

// -> leave out
/* parameterized typed test */
template<typename T>
struct AddOneTestsFixture : public ::testing::Test {};
TYPED_TEST_SUITE_P(AddOneTestsFixture);

TYPED_TEST_P(AddOneTestsFixture, doAddOne) {
    ASSERT_EQ(addOne(5), 6) << "addOne(5) != 6!";
}

REGISTER_TYPED_TEST_SUITE_P(AddOneTestsFixture, doAddOne);

using Types = testing::Types<int, long long, std::size_t>;
INSTANTIATE_TYPED_TEST_SUITE_P(TestPrefix, AddOneTestsFixture, Types);