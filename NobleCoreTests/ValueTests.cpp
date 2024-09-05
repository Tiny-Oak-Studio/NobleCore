#include "gtest/gtest.h"
#include "../Value.h"

using namespace Noble::Core::Runtime;

TEST(Value, ValueSize)
{
#ifdef SET_VALUE_64
    // Require value to be 64 bits
    EXPECT_EQ(8, sizeof(ValueType));
#else
    // Require value to be 32 bits
    EXPECT_EQ(4, sizeof(ValueType));
#endif
}