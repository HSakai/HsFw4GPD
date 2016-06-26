#pragma once

#include "FwScene.h"

class SceneSplash : public HsEngine::FwScene
{
public:
    SceneSplash ();
    virtual ~SceneSplash ();
    void ProcessUpdate (const uint deltaTime, const bool isEnterChild) override;
    void ProcessDraw (const bool isEnterChild) override;
private:
    int drawTime;
    int splashWaitTime;
    int splashFadeTime;
    int splashViewTime;
    gameplay::SpriteBatch* splashImg;
    gameplay::Vector4 splashColor;
};
