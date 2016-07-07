#pragma once

#include "FwScene.h"
#include "SplashCtrl.h"

class SplashCtrl;

class SceneSplash : public HsEngine::FwScene
{
public:
    SceneSplash ();
    virtual ~SceneSplash ();
    void ProcessInitialize ();
    void ProcessUpdate (const uint deltaTime, const bool isEnterChild) override;
    void ProcessDraw (const bool isEnterChild) override;
private:
    SplashCtrl* splashCtrl;
};
