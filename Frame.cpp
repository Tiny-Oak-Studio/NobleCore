#include "Frame.h"

namespace Noble::Core
{
    Frame::~Frame()
    {
        delete [] ops;
        delete [] constants;
    }
}
