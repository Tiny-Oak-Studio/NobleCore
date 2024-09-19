#ifndef NOBLE_CORE_FRAME_H_INCLUDED
#define NOBLE_CORE_FRAME_H_INCLUDED

#include "Value.h"
#include "Op.h"
#include "Address.h"

namespace Noble::Core
{
    /**
     * @class Frame
     * @brief Holds executable Noble Assembly Language (NAL) sequences for execution in a runtime environment.
     */
    struct Frame
    {
        /**
         * @brief Deletes all member data arrays.
         */
        ~Frame();

        /**
         * @brief Array of Noble Assembly Ops to be executed by a VM.
         *
         * This array is created by the compiler and read by the VM.
         */
        Op::Type* ops = nullptr;

        /// @brief Number of ops stored in the ops array.
        Address::Single numOps = 0;

        /**
         * @brief Array of constants to be used by this Frame.
         *
         * This array is created by the compiler and read by the VM.
         */
        Runtime::ValueType* constants = nullptr;

        /// @brief Number of constants stored in the constants array.
        Address::Single numConstants = 0;
    };
}

#endif //NOBLE_CORE_FRAME_H_INCLUDED