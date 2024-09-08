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

    void Frame::WriteConstant(ValueType value)
    {
        if (constants.Count() < Address::MaxHalf)
        {
            WriteOp(Op::Code::HalfConstant);
            const Noble::Core::Address::Half addr = constants.Count();
        }
        else if (constants.Count() < Address::MaxSingle)
        {
            WriteOp(Op::Code::Constant);
            const Noble::Core::Address::Single addr = constants.Count();
        }
        else if (constants.Count() < Address::MaxDouble)
        {
            WriteOp(Op::Code::DoubleConstant);
            const Noble::Core::Address::Double addr = constants.Count();
        }
        else
        {
            WriteOp(Op::Code::QuadConstant);
            const Noble::Core::Address::Quad addr = constants.Count();
        }
        constants.Add(value);
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
