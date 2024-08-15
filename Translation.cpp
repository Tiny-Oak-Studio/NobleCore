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

    Op::OpType* Translation::AddressToOps(Address::AddressType address)
    {
        auto* ops = new Op::OpType[OpsPerAddress];
        memcpy(ops, &address, sizeof(address));
        return ops;
    }

}
