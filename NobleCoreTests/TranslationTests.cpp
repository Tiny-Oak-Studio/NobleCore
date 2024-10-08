#include "gtest/gtest.h"
#include "../Op.h"
#include "../Address.h"
#include "../Translation.h"

using namespace Noble::Core;

/// @brief Tests that zero-ops translates to a zero address
TEST(Translation, OpsToAddressZeroes)
{
    Op::Type ops[Translation::OpsPerAddress];
    for (Op::Type & op : ops)
    {
        op = 0;
    }
    Address::Single address = 0;
    EXPECT_EQ(Translation::OpsToAddress(ops), address);
}

/// @brief Test that max-value ops translate to a max-value address
TEST(Translation, OpsToAddressMaxValue)
{
    Op::Type ops[Translation::OpsPerAddress];
    for (Op::Type & op : ops)
    {
        op = 0;
        op = ~op;
    }
    Address::Single address = 0;
    address = ~address;
    EXPECT_EQ(Translation::OpsToAddress(ops), address);
}

/// @brief Test that an asymmetric ops sequence translate to a correct address
TEST(Translation, OpsToAddressRoundTrip)
{
    Op::Type ops[Translation::OpsPerAddress];
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
    const Address::Single address = Translation::OpsToAddress(ops);
    List<Op::Type> newOps = Translation::AddressToOps(address);
    EXPECT_EQ(memcmp(newOps.GetArray(), ops, Translation::OpsPerAddress), 0);
}

/// @brief Test that an asymmetric ops sequence translate to a correct address
TEST(Translation, OpsToAddressList)
{
    List<Op::Type> ops;
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
    Address::Single address = Translation::OpsToAddress(ops, 0);
    List<Op::Type> newOps = Translation::AddressToOps(address);
    EXPECT_EQ(memcmp(newOps.GetArray(), ops.GetArray(), sizeof(address)), 0);
}

/// @brief Tests that a zero-address correctly translates to ops
TEST(Translation, AddressToOpsZero)
{
    Address::Single address = 0;
    const List<Op::Type> ops = Translation::AddressToOps(address);
    for (int i = 0; i < Translation::OpsPerAddress; ++i)
    {
        EXPECT_EQ(ops[i], 0);
    }
}

/// @brief Tests that a max-value address correctly translates to ops
TEST(Translation, AddressToOpsMaxValue)
{
    Address::Single address = 0;
    address = ~address;

    Op::Type maxValueOpType = 0;
    maxValueOpType = ~maxValueOpType;

    const List<Op::Type> ops = Translation::AddressToOps(address);
    for (int i = 0; i < Translation::OpsPerAddress; ++i)
    {
        EXPECT_EQ(ops[i], maxValueOpType);
    }
}
