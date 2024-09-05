#include "Frame.h"

namespace Noble::Core
{
    /// @brief We simply enumerate frames as they're created
    uint32_t Frame::NextFrameID = 0;

    Frame::Frame()
    {
        frameID = NextFrameID++;
    }

    void Frame::WriteOp(const Op::OpType &op)
    {
        ops.Add(op);
    }

    Op::OpType Frame::ReadOp(const Address::AddressType& address)
    {
        return ops[address];
    }

    void Frame::WriteAddress(const Address::AddressType &address)
    {
        ops.Add(Translation::AddressToOps(address));
    }

    Address::AddressType Frame::ReadAddress(const Address::AddressType &address) const
    {
        return Translation::OpsToAddress(ops, address);
    }

    Address::AddressType Frame::AddConstant(Value value)
    {
        constants.Add(value);
        return constants.Count() - 1;
    }

    const Value& Frame::ReadConstant(Address::AddressType address) const
    {
        return constants[address];
    }

    const Op::OpType* Frame::GetOps() const
    {
        return ops.GetArray();
    }
}
