#ifndef NOBLE_CORE_FRAME_H_INCLUDED
#define NOBLE_CORE_FRAME_H_INCLUDED

#include "Value.h"
#include "Op.h"
#include "Address.h"

namespace Noble::Core
{
    /**
     * @class Frame
     * @brief Holds executable Noble Assembly Sequences (NAS) for execution in a runtime environment.
     */
    struct Frame
    {
        /**
         * @brief Deletes the ops and constant array.
         */
        ~Frame();

        /**
         * @brief Array of Noble Assembly Ops to be executed by a VM.
         */
        Op::Type* ops = nullptr;

        /// @brief Number of ops stored in the array.
        Address::Single numOps = 0;

        /**
         * @brief Array of constants used be the NAS in this Frame.
         */
        Runtime::ValueType* constants = nullptr;

        /// @brief Number of constants stored in the array.
        Address::Single numConstants = 0;
    };
}

#endif //NOBLE_CORE_FRAME_H_INCLUDED