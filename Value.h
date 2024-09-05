#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED

/**
 * We assume a 32-bit float type for our NaN-boxing
 */

#ifdef __AVR__
#include <string.h>
#include <stdint.h>
#else
#include <cstring>
#include <cstdint>
#include <stdfloat>
#endif

namespace Noble::Core::Runtime
{
#ifdef __AVR__
    typedef uint32_t ValueType;
    typedef float FloatType;
    constexpr ValueType QNaN = 0x7fe00000;
    constexpr ValueType SignBit = 0x80000000;
#else
    #ifdef SET_VALUE_64
        typedef uint64_t ValueType;
        typedef std::float64_t FloatType;
        constexpr ValueType QNaN = 0x7ffc000000000000;
        constexpr ValueType SignBit = 0x8000000000000000;
    #else
        typedef uint32_t ValueType;
        typedef std::float32_t FloatType;
        constexpr ValueType QNaN = 0x7fe00000;
        constexpr ValueType SignBit = 0x80000000;
    #endif
#endif
    constexpr ValueType NullTag =  0;
    constexpr ValueType TrueTag =  1;
    constexpr ValueType FalseTag = 2;

    constexpr ValueType NullValue =  QNaN | NullTag;
    constexpr ValueType TrueValue =  QNaN | TrueTag;
    constexpr ValueType FalseValue = QNaN | FalseTag;

    ValueType ToValue(FloatType data);
    ValueType ToValue(bool data);

    FloatType ToFloat(ValueType value);
    bool ToBool(ValueType value);

    bool IsNull(ValueType value);
    bool IsFloat(ValueType value);
    bool IsBool(ValueType value);
}

#endif //VALUE_H_INCLUDED
