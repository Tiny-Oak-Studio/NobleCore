#include "Frame.h"

namespace Noble::Core
{
    /// @brief We simply enumerate frames as they're created
    uint32_t Frame::NextFrameID = 0;

    Frame::Frame()
    {
        frameID = NextFrameID++;
    }

    void Frame::WriteOp(const Op::Type &op)
    {
        ops.Add(op);
    }

    Op::Type Frame::ReadOp(const Address::AddressType& address)
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

    Address::AddressType Frame::AddConstant(const ValueType value)
    {
        constants.Add(value);
        return constants.Count() - 1;
    }

    void Frame::WriteConstant(ValueType value)
    {

    }

    const ValueType& Frame::ReadConstant(const Address::AddressType address) const
    {
        return constants[address];
    }

    const List<Op::Type> &Frame::GetOps() const
    {
        return ops;
    }
}
