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
        static constexpr uint8_t OpsPerAddress = sizeof (Address::Single) / sizeof (Op::Type);

        /**
         * @brief Converts OpTypes to a Single
         * @param ops The OpTypes to convert to a Single
         * @return A Single created from the bits of the provided OpTypes
         *
         * Type-puns the bytes from the given OpTypes into a Single.
         **/
        static Address::Single OpsToAddress(Op::Type ops[OpsPerAddress]);

        /**
         * @brief Reads an address from given list at the specified index
         * @param list The list to read from
         * @param index The element index to read at
         * @return The address created from the bits starting in the list at the given index
         */
        static Address::Single OpsToAddress(const List<Op::Type>& list, Address::Single index);

        /**
         * @brief Converts a Single address to a list of OpTypes
         * @param address The address to be converted
         * @return A list of OpTypes containing the bits of the given address
         */
        static List<Op::Type> AddressToOps(const Address::Single& address);
    };
}

#endif //NOBLE_CORE_MEMORY_H_INCLUDED