#ifndef NOBLE_CORE_OP_H_INCLUDED
#define NOBLE_CORE_OP_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.

namespace Noble::Core
{
    /// @brief Contains definitions for the sizes of various atomic objects.
    class Op
    {
    public:
        /// @brief Ops are the basic operation type of the NobleVM.
        typedef uint8_t Type;

        /// @brief All operations codes supported by the NobleVM.
        enum Code : Type
        {
            Add = 0,
            Constant,
            ConstantString,
            DefineGlobal,
            Divide,
            Equal,
            False,
            GetGlobal,
            GetLocal,
            Greater,
            GreaterEqual,
            Jump,
            JumpIfFalse,
            JumpIfTrue,
            Less,
            LessEqual,
            Loop,
            Multiply,
            Negate,
            Not,
            NotEqual,
            Null,
            Pop,
            PopN,
            Print,
            Return,
            SetGlobal,
            SetLocal,
            Subtract,
            True
        };
    };
}

#endif //NOBLE_CORE_OP_H_INCLUDED