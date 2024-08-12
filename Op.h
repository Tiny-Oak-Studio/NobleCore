#ifndef NOBLE_CORE_OP_H_INCLUDED
#define NOBLE_CORE_OP_H_INCLUDED

#include <stdint.h> //Use the older header to be compatible with Arduino.

namespace Noble::Core
{
    /// @brief Contains defintions for the sizes of various atomic objects.
    class Op
    {
    public:
        /// @brief Ops are the basic operation type of the NobleVM.
        typedef uint8_t OpType;

        /// @brief All operations codes supported by the NobleVM.
        enum Code : OpType
        {
            Add = 0,
            Constant,
            Divide,
            Greater,
            Less,
            Multiply,
            Not,
            Return,
            Subtract, 
        };

    protected:

    };
}

#endif //NOBLE_CORE_OP_H_INCLUDED