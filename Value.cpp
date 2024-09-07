#include "Value.h"

namespace Noble::Core::Runtime
{
    ValueType ToValue(const FloatType data)
    {
        ValueType value;
        memcpy(&value, &data, sizeof(FloatType));
        return value;
    }

    ValueType ToValue(const bool data)
    {
        return data ? TrueValue : FalseValue;
    }

    FloatType ToFloat(const ValueType value)
    {
        FloatType data;
        memcpy(&data, &value, sizeof(ValueType));
        return data;
    }

    bool ToBool(const ValueType value)
    {
        return value == TrueValue;
    }

    bool IsNull(const ValueType value)
    {
        return value == NullValue;
    }

    bool IsFloat(const ValueType value)
    {
        return (value & QNaN) != QNaN;
    }

    bool IsBool(const ValueType value)
    {
        return value == TrueValue || value == FalseValue;
    }
}
