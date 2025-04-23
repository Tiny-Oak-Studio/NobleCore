#include "gtest/gtest.h"
#include "../Value.h"

using namespace Noble::Core::Runtime;

TEST(Value, TargetSizes)
{
#ifdef SET_VALUE_64
    // Require value to be 64 bits
    EXPECT_EQ(8, sizeof(ValueType));
#else
    // Require value to be 32 bits
    EXPECT_EQ(4, sizeof(ValueType));
#endif
    EXPECT_EQ(sizeof(ValueType), sizeof(FloatType));
}

TEST(Value, FloatToValue)
{
    FloatType data = 1234.4342f;
    ValueType value = ToValue(data);
    EXPECT_TRUE(IsFloat(value));
    EXPECT_EQ(memcmp(&data, &value, sizeof(ValueType)), 0);
}

TEST(Value, FloatRoundTrip)
{
    FloatType data = 12339234.4382342f;
    ValueType value = ToValue(data);
    EXPECT_TRUE(IsFloat(value));
    FloatType finalData = ToFloat(value);
    EXPECT_EQ(data, finalData);
}

TEST(Value, BoolRoundTrip)
{
    bool data = false;
    ValueType value = ToValue(data);
    EXPECT_TRUE(IsBool(value));
    EXPECT_FALSE(ToBool(value));
}

TEST(Value, Null)
{
    ValueType value = NullValue;
    EXPECT_TRUE(IsNull(value));
}
