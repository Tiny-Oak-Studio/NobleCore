#include "gtest/gtest.h"
#include "../List.h"

using namespace Noble::Core;

/// @brief Add one element and test access and equality
TEST(List, AddOneInt)
{
    List<int> list;
    list.Add(142);
    EXPECT_EQ(list[0], 142);
}

/// @brief Add 20 elements and check capacity has expanded correctly
TEST(List, CheckTwentyIntCapacity)
{
    List<int> list;
    for (int i = 0; i < 20; ++i)
    {
        list.Add(i);
    }
    EXPECT_EQ(list.Capacity(), 32);
}

/// @brief Add 20 elements and check the count matches
TEST(List, CheckTwentyIntCount)
{
    List<int> list;
    for (int i = 0; i < 20; ++i)
    {
        list.Add(i);
    }
    EXPECT_EQ(list.Count(), 20);
}

/// @brief Add 100 chars and check elements survive realloc
TEST(List, AddOneHundredChar)
{
    List<char> list;
    for (int i = 0; i < 100; ++i)
    {
        list.Add(static_cast<char>(i + 100));
    }
    for (int i = 0; i < 100; ++i)
    {
        EXPECT_EQ(list[i], static_cast<char>(i + 100));
    }
}

/// @brief Add one element and test pop equality
TEST(List, AddOnePopOneInt)
{
    List<int> list;
    list.Add(23359);
    EXPECT_EQ(list.Pop(), 23359);
}

/// @brief Add 1000 elements, then pop 1000 and check equality
TEST(List, AddOneThousandPopOneThousandInt)
{
    List<int> list;
    for (int i = 1; i <= 1000; ++i)
    {
        list.Add(i);
    }
    for (int i = 1; i <= 1000; ++i)
    {
        EXPECT_EQ(list.Pop(), 1001 - i);
    }
}
