#ifndef NOBLE_CORE_ADDRESS_H_INCLUDED
#define NOBLE_CORE_ADDRESS_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.

/**
 * We assume a 16-bit architecture but provide room for 32 and 64-bit
 * architectures.
 */
namespace Noble::Core::Address
{
#ifdef SET_ADDRESS_64
    typedef uint64_t Single;
#elif SET_ADDRESS_32
    typedef uint32_t Single;
#else
    typedef uint16_t Single;
#endif
}

#endif //NOBLE_CORE_ADDRESS_H_INCLUDED