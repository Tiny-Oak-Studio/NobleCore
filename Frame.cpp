#include "Frame.h"

namespace Noble::Core
{
    uint32_t Frame::NextFrameID = 0;

    Frame::Frame()
    {
        frameID = NextFrameID++;
    }

    void Frame::WriteOp(const Op::OpType &op)
    {
        ops.Add(op);
    }

    void Frame::WriteAddress(const Address::AddressType &address)
    {
        ops.Add(Translation::AddressToOps(address));
    }

}