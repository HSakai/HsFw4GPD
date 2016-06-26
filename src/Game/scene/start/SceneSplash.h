#pragma once

#include "FwScene.h"

class SceneSplash : public HsEngine::FwScene
{
public:
    SceneSplash ();
    virtual ~SceneSplash ();
    void ProcessUpdate (const uint deltaTime, const bool isEnterChild) override;
};
