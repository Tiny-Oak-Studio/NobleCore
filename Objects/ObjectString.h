#ifndef NOBLE_CORE_OBJECTSTRING_H
#define NOBLE_CORE_OBJECTSTRING_H

#include "Object.h"
#include "../Address.h"

namespace Noble::Core
{
    struct ObjectString final : Object
    {
        ObjectString();

        Address::Single length = 0;
        char* characters = nullptr;
    };
} //Noble::Core

#endif //NOBLE_CORE_OBJECTSTRING_H
