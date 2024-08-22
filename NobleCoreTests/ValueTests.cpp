#include "gtest/gtest.h"
#include "../Value.h"

using namespace Noble::Core;

TEST(Value, ValueSize)
{
    // Require value to be 32 bits
    EXPECT_EQ(4, sizeof(Value));
}