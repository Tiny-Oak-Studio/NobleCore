#ifndef NOBLE_CORE_DEBUG_H
#define NOBLE_CORE_DEBUG_H

#include <sstream>

#include "Op.h"

namespace Noble::Core::Debug
{
    std::string OpToString(Op::Code op);
} // Noble::Core

#endif //NOBLE_CORE_DEBUG_H
