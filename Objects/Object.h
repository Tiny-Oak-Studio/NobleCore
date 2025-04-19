#ifndef NOBLE_CORE_OBJECT_H
#define NOBLE_CORE_OBJECT_H

#include <stdint.h> //Use the older header to be compatible with Arduino.

namespace Noble::Core
{
    struct Object
    {
        enum Type : uint8_t
        {
            String = 0
        };

        Type type;
    };
} // Noble::Core

#endif //NOBLE_CORE_OBJECT_H
