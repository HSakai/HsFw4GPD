#pragma once

#include "gameplay.h"

namespace HsEngine
{
    class Skybox : public gameplay::Node
    {
    public:
        static Skybox* create (const char* materialPath, const char* nodeName);
    protected:
        explicit Skybox (const char* id);
        ~Skybox ();
    };
}
