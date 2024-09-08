#ifndef NOBLE_CORE_FRAME_H_INCLUDED
#define NOBLE_CORE_FRAME_H_INCLUDED

#include <stdint.h> //Use old header for Arduino compatibility
#include "Value.h"
#include "List.h"
#include "Op.h"
#include "Translation.h"

using namespace Noble::Core::Runtime;

namespace Noble::Core
{
    /// @brief Contains Noble Assembly Language Sequence (NAL) information and translation methods.
    class Frame
    {
    public:
        /// @brief Writes an op to this frame's underlying array
        void WriteOp(const Op::Type& op);

        /// @brief Returns the op at the specified address
        Op::Type ReadOp(const Address::Single& address);

        /// @brief Writes an address into the frame's underlying array
        void WriteAddress(const Address::Single& address);

        /// @brief Reads an address from the underlying array at the provided index address
        Address::Single ReadAddress(const Address::Single& address) const;

        /// @brief Adds a constant to this frame
        Address::Single AddConstant(ValueType value);

        /// @brief Writes the value and automatically decides the appropriate op type.
        void WriteConstant(ValueType value);

        /// @brief Reads a constant at the given address.
        const ValueType& ReadConstant(Address::Single address) const;

        /// @brief Returns a const-ref to the ops list
        const List<Op::Type>& GetOps() const;
    protected:
        /// @brief Storage for reading/writing ops in the compiler
        List<Op::Type> ops;

        /// @brief Storage for the constants used in this frame
        List<ValueType> constants;
    };
}

#endif //NOBLE_CORE_FRAME_H_INCLUDED