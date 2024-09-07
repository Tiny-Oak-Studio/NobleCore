#include "Translation.h"

#include <string.h> //Use the older header for Arduino compatibility.

namespace Noble::Core
{
    Address::AddressType Translation::OpsToAddress(Op::Type ops[OpsPerAddress])
    {
        Address::AddressType address;
        memcpy(&address, ops, sizeof(address));
        return address;
    }

    Address::AddressType Translation::OpsToAddress(const List<Op::Type>& list, const Address::AddressType index)
    {
        Address::AddressType address;
        memcpy(&address, &list.GetArray()[index], sizeof(address));
        return address;
    }

    List<Op::Type> Translation::AddressToOps(const Address::AddressType& address)
    {
        List<Op::Type> ops;
        ops.Resize(sizeof(address));
        memcpy(ops.GetArray(), &address, sizeof(address));
        return ops;
    }
}
