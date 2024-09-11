#include "Frame.h"

namespace Noble::Core
{
    void Frame::WriteOp(const Op::Type &op)
    {
        ops.Add(op);
    }

    Op::Type Frame::ReadOp(const Address::Single& address)
    {
        return ops[address];
    }

    void Frame::WriteAddress(const Address::Single &address)
    {
        ops.Add(Translation::AddressToOps(address));
    }

    Address::Single Frame::ReadAddress(const Address::Single &address) const
    {
        return Translation::OpsToAddress(ops, address);
    }

    Address::Single Frame::AddConstant(const ValueType value)
    {
        constants.Add(value);
        return constants.Count() - 1;
    }

    void Frame::WriteConstant(const ValueType value)
    {
        WriteOp(Op::Code::Constant);
        WriteAddress(AddConstant(value));
    }

    const ValueType& Frame::ReadConstant(const Address::Single address) const
    {
        return constants[address];
    }

    const List<Op::Type> &Frame::GetOps() const
    {
        return ops;
    }
}
