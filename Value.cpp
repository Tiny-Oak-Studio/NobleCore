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

    ValueType ToValue(struct Object* object)
    {
        return static_cast<ValueType>(SignBit | QNaN | reinterpret_cast<uintptr_t>(object));
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

    Object* ToObject(const ValueType value)
    {
        return reinterpret_cast<Object *>(static_cast<uintptr_t>(value & ~(SignBit | QNaN)));
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

    bool IsString(const ValueType value)
    {
        return IsObjectType(value, Object::Type::String);
    }

    bool IsObject(const ValueType value)
    {
        return (value & (QNaN | SignBit)) == (QNaN | SignBit);
    }

    bool IsObjectType(const ValueType value, const Object::Type type)
    {
        return IsObject(value) and ToObject(value)->type == type;
    }


    bool IsFalsey(const ValueType value)
    {
        return IsNull(value) or (IsBool(value) and !ToBool(value));
    }

    bool IsTruthy(const ValueType value)
    {
        return IsBool(value) and ToBool(value);
    }
}
