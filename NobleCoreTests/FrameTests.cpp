#include "gtest/gtest.h"
#include "../Frame.h"

using namespace Noble::Core;

/// @brief Write an op and then read it and compare the result
TEST(Frame, WriteReadOneOp)
{
    constexpr Op::OpType op = 123;
    Frame frame;
    frame.WriteOp(op);
    EXPECT_EQ(frame.ReadOp(0), op);
}

TEST(Frame, WriteReadOneAddress)
{
    constexpr Address::AddressType address = 12313;
    Frame frame;
    frame.WriteAddress(address);
    EXPECT_EQ(frame.ReadAddress(0), address);
}

TEST(Frame, WriteReadOneOpOneAddress)
{
    constexpr Op::OpType op = 123;
    constexpr Address::AddressType address = 12313;

    Frame frame;
    frame.WriteOp(op);
    frame.WriteAddress(address);
    EXPECT_EQ(frame.ReadAddress(1), address);
    EXPECT_EQ(frame.ReadOp(0), op);
}

TEST(Frame, WriteReadOneHundredOpsAndAddresses)
{
    Frame frame;
    for (Address::AddressType i = 0; i < 100; ++i)
    {
        const Op::OpType op = i;
        const Address::AddressType address = 12313 + i;

        frame.WriteOp(op);
        frame.WriteAddress(address);
    }

    for (Address::AddressType i = 0; i < 100; ++i)
    {
        const Op::OpType op = i;
        const Address::AddressType address = 12313 + i;

        EXPECT_EQ(frame.ReadAddress(i * (sizeof(Op::OpType) + Translation::OpsPerAddress) + 1), address);
        EXPECT_EQ(frame.ReadOp(i * (sizeof(Op::OpType) + Translation::OpsPerAddress)), op);
    }
}