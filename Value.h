#ifndef VALUE_H
#define VALUE_H

/**
 * We assume a 32-bit float type for our NaN-boxing
 */

#ifdef __AVR__

namespace Noble::Core
{
    typedef float Value;
}

#else

#include <stdfloat>

namespace Noble::Core
{
    typedef std::float32_t Value;
} // Noble::Core

#endif //__AVR__

#endif //VALUE_H
