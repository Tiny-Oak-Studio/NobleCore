#ifndef NOBLE_CORE_MEMORY_H_INCLUDED
#define NOBLE_CORE_MEMORY_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.
#include "Op.h"
#include "Address.h"
#include "List.h"

namespace Noble::Core
{
    /// @brief Contains definitions for the sizes of various atomic objects.
    class Translation
    {
    public:
        /// @brief Compile-time constant for converting Ops and Addresses.
        static constexpr uint8_t OpsPerAddress = sizeof (Address::AddressType) / sizeof (Op::OpType);

        /**
         * @brief Converts OpTypes to an AddressType
         * @param ops The OpTypes to convert to an AddressType
         * @return An AddressType created from the bits of the provided OpTypes
         *
         * Type-puns the bytes from the given OpTypes into an AddressType.
         **/
        static Address::AddressType OpsToAddress(Op::OpType ops[OpsPerAddress]);

        /**
         * @brief Reads an address from given list at the specified index
         * @param list The list to read from
         * @param index The element index to read at
         * @return The address created from the bits starting in the list at the given index
         */
        static Address::AddressType OpsToAddress(const List<Op::OpType>& list, Address::AddressType index);

        /**
         * @brief Converts an AddressType to a list of OpTypes
         * @param address The address to be converted
         * @return A list of OpTypes containing the bits of the given address
         */
        static List<Op::OpType> AddressToOps(const Address::AddressType& address);
    };
}

#endif //NOBLE_CORE_MEMORY_H_INCLUDED