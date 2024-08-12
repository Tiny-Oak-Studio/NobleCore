#ifndef NOBLE_CORE_MEMORY_H_INCLUDED
#define NOBLE_CORE_MEMORY_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.

namespace Noble::Core
{
    /// @brief Contains defintions for the sizes of various atomic objects.
    class Memory
    {
    public:

        /// @brief Compile-time constant for converting Ops and Addresses.
        const uint8_t OpsPerAddress = sizeof (Address) / sizeof (Op);
    protected:

    };
}

#endif //NOBLE_CORE_MEMORY_H_INCLUDED