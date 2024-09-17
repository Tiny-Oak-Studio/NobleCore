#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED

/**
 * Can switch between 64-bit and 32-bit values by defining SET_VALUE_64
 */

#ifdef __AVR__
#include <string.h> //For memcpy for Arduino
#include <stdint.h> //For uint32_t for Arduino
#else
#include <cstring>  //For memcpy
#include <cstdint>  //For uint32_t and uint64_t
#include <stdfloat> //For std::float32_t
#endif

namespace Noble::Core::Runtime
{
#ifdef __AVR__
    typedef uint32_t ValueType;
    typedef float FloatType;
    constexpr ValueType QNaN = 0x7fe00000;
    constexpr ValueType SignBit = 0x80000000;
#elif SET_VALUE_64
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

    /**
     * @brief Defines the bits used in a QNaN to represent a null value.
     */
    constexpr ValueType NullTag =  0;

    /**
     * @brief Defines the bits used in a QNaN to represent a boolean true value.
     */
    constexpr ValueType TrueTag =  1;

    /**
     * @brief Defines the bits used in a QNaN to represent a boolean false value.
     */
    constexpr ValueType FalseTag = 2;

    /**
     * @brief Defines the literal value for 'null'.
     */
    constexpr ValueType NullValue =  QNaN | NullTag;

    /**
     * @brief Defines the literal value for boolean 'true'.
     */
    constexpr ValueType TrueValue =  QNaN | TrueTag;

    /**
     * @brief Defines the literal value for boolean 'false'.
     */
    constexpr ValueType FalseValue = QNaN | FalseTag;

    /**
     * @brief Converts the target platform's native floating-point type into a ValueType.
     * @param data The floating-point type to convert to a ValueType
     * @return A ValueType with bits exactly matching the given float parameter.
     *
     * This function uses memcpy() semantic type-punning to copy the bits from
     * the data parameter directly into a ValueType and returns it.
     */
    ValueType ToValue(FloatType data);

    /**
     * @brief Returns the ValueType equivalent of the provided bool.
     * @param data A bool to convert to ValueType.
     * @return A ValueType representing the value of the given bool.
     */
    ValueType ToValue(bool data);

    FloatType ToFloat(ValueType value);
    bool ToBool(ValueType value);

    bool IsNull(ValueType value);
    bool IsFloat(ValueType value);
    bool IsBool(ValueType value);
}

#endif //VALUE_H_INCLUDED
