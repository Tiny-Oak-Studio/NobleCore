#include "Translation.h"

#include <string.h> //Use the older header for Arduino compatibility.

namespace Noble::Core
{
    Address::AddressType Translation::OpsToAddress(Op::OpType ops[OpsPerAddress])
    {
        Address::AddressType address;
        memcpy(&address, ops, sizeof(address));
        return address;
    }

    List<Op::OpType> Translation::AddressToOps(const Address::AddressType& address)
    {
        List<Op::OpType> ops(OpsPerAddress);
        memcpy(ops.GetArray(), &address, sizeof(address));
        return ops;
    }

}
