#include <iostream>
#include "Utils.h"

namespace HsEngine
{
    float Lerp (float from , float to, float process)
    {
        float addValue = (to - from) * process;
        return from + addValue;
    }

    void PutLog (const std::string& logText)
    {
        std::cout << logText << std::endl;
    }
}
