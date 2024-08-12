#ifndef NOBLE_CORE_MEMORY_H_INCLUDED
#define NOBLE_CORE_MEMORY_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.
#include "Op.h"
#include "Address.h"

namespace Noble::Core
{
    /// @brief Contains defintions for the sizes of various atomic objects.
    class Translation
    {
    public:
        /// @brief Compile-time constant for converting Ops and Addresses.
        const uint8_t OpsPerAddress = sizeof (Address) / sizeof (Op);

        
    };
}

#endif //NOBLE_CORE_MEMORY_H_INCLUDED