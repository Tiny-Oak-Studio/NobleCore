#ifndef NOBLE_CORE_ADDRESS_H_INCLUDED
#define NOBLE_CORE_ADDRESS_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.

/**
 * We assume a 16-bit architecture but provide room for 32 and 64-bit
 * architectures too.
 */
namespace Noble::Core::Address
{
    typedef uint64_t Quad;
    typedef uint32_t Double;
    typedef uint16_t Single;
    typedef uint8_t Half;

    constexpr Quad MaxQuad =     ~static_cast<Quad>(0);
    constexpr Double MaxDouble = ~static_cast<Double>(0);
    constexpr Single MaxSingle = ~static_cast<Single>(0);
    constexpr Half MaxHalf =     ~static_cast<Half>(0);
}

#endif //NOBLE_CORE_ADDRESS_H_INCLUDED