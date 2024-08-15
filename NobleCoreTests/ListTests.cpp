#include "gtest/gtest.h"
#include "../List.h"

using namespace Noble::Core;

TEST(List, AddOneInt)
{
    List<int> list;
    list.Add(142);
    EXPECT_EQ(list[0], 142);
}

TEST(List, CheckTwentyIntCapacity)
{
    List<int> list;
    for (int i = 0; i < 20; ++i)
    {
        list.Add(i);
    }
    EXPECT_EQ(list.Capacity(), 32);
}

TEST(List, CheckTwentyIntCount)
{
    List<int> list;
    for (int i = 0; i < 20; ++i)
    {
        list.Add(i);
    }
    EXPECT_EQ(list.Count(), 20);
}

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

TEST(List, AddOnePopOneInt)
{
    List<int> list;
    list.Add(23359);
    EXPECT_EQ(list.Pop(), 23359);
}

TEST(List, AddOneThousandPopOneThousandInt)
{
    List<int> list;
    for (int i = 0; i < 10; ++i)
    {
        list.Add(i);
    }
    for (int i = 0; i < 10; ++i)
    {
        EXPECT_EQ(list.Pop(), 9 - i);
    }
}
