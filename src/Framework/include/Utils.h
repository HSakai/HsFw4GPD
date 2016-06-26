/*
 * 汎用Utility
 */
#pragma once

#include <string>

typedef unsigned int uint;

namespace HsEngine
{
    /*
     * 線形補間関数
     */
    float Lerp (float from , float to, float process);

#ifdef DEBUG
    // coutでコンソール出力
    void PutLog (const std::string& logText);
#endif
}
