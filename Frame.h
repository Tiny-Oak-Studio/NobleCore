#ifndef NOBLE_CORE_FRAME_H_INCLUDED
#define NOBLE_CORE_FRAME_H_INCLUDED

#include <stdint.h> //Use old header for Arduino compatibility
#include "List.h"
#include "Op.h"
#include "Translation.h"

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

        /// @brief Writes an address into the frame's underlying array
        void WriteAddress(const Address::AddressType& address);
    protected:
        /// @brief Internal variable for keeping track of how many Frames have been created.
        static uint32_t NextFrameID;

        /// @brief Storage for reading/writing ops in the compiler
        List<Op::OpType> ops;

        /// @brief The unique ID for this Frame.
        uint32_t frameID;
    };
}

#endif //NOBLE_CORE_FRAME_H_INCLUDED