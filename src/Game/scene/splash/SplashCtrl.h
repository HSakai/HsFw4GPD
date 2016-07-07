#pragma once

#include "SceneCtrl.h"
#include "gameplay.h"
#include "FwBatchSprite.h"

namespace HsEngine
{
    class FwBatchSprite;
}

class SplashCtrl : public HsEngine::SceneCtrl
{
public:
    explicit SplashCtrl ();
    ~SplashCtrl ();
    void OnInitialize ();
    void OnUpdate (const unsigned int deltaTime, const bool isEnterChild);
    void OnDestroy ();
    HsEngine::FwBatchSprite* GetLogo () const;
    const bool IsAnimationComplete ();
private:
    int drawTime;
    int splashWaitTime;
    int splashFadeTime;
    int splashViewTime;
    int splashFadeWaitTime;
    gameplay::SpriteBatch* splashImg;
    HsEngine::FwBatchSprite* logo;
    gameplay::Vector4 splashColor;
};
