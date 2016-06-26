/*
 * 汎用Utility
 */
#pragma once

#include <string>

typedef unsigned int uint;

namespace HsEngine
{
#ifdef DEBUG
    // coutでコンソール出力
    void PutLog (const std::string& logText);
#endif
}
