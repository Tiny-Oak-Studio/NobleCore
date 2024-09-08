#include "Translation.h"

#include <string.h> //Use the older header for Arduino compatibility.

namespace Noble::Core
{
    Address::Single Translation::OpsToAddress(Op::Type ops[OpsPerAddress])
    {
        Address::Single address;
        memcpy(&address, ops, sizeof(address));
        return address;
    }

    Address::Single Translation::OpsToAddress(const List<Op::Type>& list, const Address::Single index)
    {
        Address::Single address;
        memcpy(&address, &list.GetArray()[index], sizeof(address));
        return address;
    }

    List<Op::Type> Translation::AddressToOps(const Address::Single& address)
    {
        List<Op::Type> ops;
        ops.Resize(sizeof(address));
        memcpy(ops.GetArray(), &address, sizeof(address));
        return ops;
    }
}
