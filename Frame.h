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
        /// @brief Initialises the Frame and generates its ID
        Frame();

        /// @brief Writes an op to this frame's underlying array
        void WriteOp(const Op::OpType& op);

        /// @brief Returns the op at the specified address
        Op::OpType ReadOp(const Address::AddressType& address);

        /// @brief Writes an address into the frame's underlying array
        void WriteAddress(const Address::AddressType& address);

        /// @brief Reads an address from the underlying array at the provided index address
        Address::AddressType ReadAddress(const Address::AddressType& address) const;

        /// @brief Adds a constant to this frame
        Address::AddressType AddConstant(ValueType value);

        /// @brief Reads a constant at the given address.
        const ValueType& ReadConstant(Address::AddressType address) const;

        /// @brief Returns a pointer to the start of this frame's op-array
        const Op::OpType* GetOps() const;
    protected:
        /// @brief Internal variable for keeping track of how many Frames have been created.
        static uint32_t NextFrameID;

        /// @brief Storage for reading/writing ops in the compiler
        List<Op::OpType> ops;

        /// @brief Storage for the constants used in this frame
        List<ValueType> constants;

        /// @brief The unique ID for this Frame.
        uint32_t frameID;
    };
}

#endif //NOBLE_CORE_FRAME_H_INCLUDED