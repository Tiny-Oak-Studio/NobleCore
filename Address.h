#ifndef NOBLE_CORE_ADDRESS_H_INCLUDED
#define NOBLE_CORE_ADDRESS_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.

namespace Noble::Core
{
    /// @brief Provides translation services for a 16-bit address space.
    class Address
    {
    public:
        /// @brief Type for spanning the address space of ATMega chips.
        typedef uint16_t AddressType;
    };
}

#endif //ADDRESS_H_INCLUDED