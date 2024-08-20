#include "gtest/gtest.h"
#include "../Op.h"
#include "../Address.h"
#include "../Translation.h"

using namespace Noble::Core;

/// @brief Tests that zero-ops translates to a zero address
TEST(Translation, OpsToAddressZeroes)
{
    Op::OpType ops[Translation::OpsPerAddress];
    for (Op::OpType & op : ops)
    {
        op = 0;
    }
    Address::AddressType address = 0;
    EXPECT_EQ(Translation::OpsToAddress(ops), address);
}

/// @brief Test that max-value ops translate to a max-value address
TEST(Translation, OpsToAddressMaxValue)
{
    Op::OpType ops[Translation::OpsPerAddress];
    for (Op::OpType & op : ops)
    {
        op = 0;
        op = ~op;
    }
    Address::AddressType address = 0;
    address = ~address;
    EXPECT_EQ(Translation::OpsToAddress(ops), address);
}

/// @brief Test that an asymmetric ops sequence translate to a correct address
TEST(Translation, OpsToAddressRoundTrip)
{
    Op::OpType ops[Translation::OpsPerAddress];
    for (int i = 0; i < Translation::OpsPerAddress; ++i)
    {
        if (i == 0)
        {
            ops[i] = 102;
        }
        else
        {
            ops[i] = 75;
        }
    }
    Address::AddressType address = Translation::OpsToAddress(ops);
    List<Op::OpType> newOps = Translation::AddressToOps(address);
    EXPECT_EQ(memcmp(newOps.GetArray(), ops, 2), 0);
}

/// @brief Test that an asymmetric ops sequence translate to a correct address
TEST(Translation, OpsToAddressList)
{
    List<Op::OpType> ops;
    for (int i = 0; i < Translation::OpsPerAddress; ++i)
    {
        if (i == 0)
        {
            ops[i] = 102;
        }
        else
        {
            ops[i] = 75;
        }
    }
    Address::AddressType address = Translation::OpsToAddress(ops);
    List<Op::OpType> newOps = Translation::AddressToOps(address);
    EXPECT_EQ(memcmp(newOps.GetArray(), ops, 2), 0);
}

/// @brief Tests that a zero-address correctly translates to ops
TEST(Translation, AddressToOpsZero)
{
    Address::AddressType address = 0;
    const List<Op::OpType> ops = Translation::AddressToOps(address);
    for (int i = 0; i < Translation::OpsPerAddress; ++i)
    {
        EXPECT_EQ(ops[i], 0);
    }
}

/// @brief Tests that a max-value address correctly translates to ops
TEST(Translation, AddressToOpsMaxValue)
{
    Address::AddressType address = 0;
    address = ~address;

    Op::OpType maxValueOpType = 0;
    maxValueOpType = ~maxValueOpType;

    const List<Op::OpType> ops = Translation::AddressToOps(address);
    for (int i = 0; i < Translation::OpsPerAddress; ++i)
    {
        EXPECT_EQ(ops[i], maxValueOpType);
    }
}
