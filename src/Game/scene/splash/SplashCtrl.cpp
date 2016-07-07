#include "SplashCtrl.h"
#include "Utils.h"
#include "../../../Main.h"

SplashCtrl::SplashCtrl () :
    drawTime (0),
    splashWaitTime (500),
    splashFadeTime (2000),
    splashViewTime (1000),
    splashFadeWaitTime (1000),
    splashImg (nullptr),
    logo (nullptr),
    splashColor (gameplay::Vector4::one ()),
    HsEngine::SceneCtrl ()
{
}

SplashCtrl::~SplashCtrl ()
{
}

void SplashCtrl::OnInitialize ()
{
    splashImg = gameplay::SpriteBatch::create ("res/logo_powered_white.png");
    logo = HsEngine::FwBatchSprite::create (splashImg, 512, 512, gameplay::Vector4 (0, 1, 1, 0));
    logo->SetPosition (Main::getInstance ()->getWidth () * 0.5f, Main::getInstance()->getHeight () * 0.5f);
    
    splashColor.w = 0;
    logo->SetColor (splashColor);
}

void SplashCtrl::OnUpdate (const unsigned int deltaTime, const bool isEnterChild)
{
    drawTime += deltaTime;

    if (IsAnimationComplete ())
    {
        splashColor.w = 0;
        logo->SetColor (splashColor);
        return;
    }

    if (drawTime < splashWaitTime)
    {
        return;
    }

    float viewTime = drawTime - splashWaitTime;
    float halfTime = splashFadeTime * 0.5f;
    if (viewTime < halfTime)
    {
        splashColor.w = HsEngine::Lerp (0.0f, 1.0f, viewTime / halfTime);
    }
    else if (viewTime < halfTime + splashViewTime)
    {
        splashColor.w = 1;
    }
    else
    {
        splashColor.w = HsEngine::Lerp (1.0f, 0.0f, (viewTime - (halfTime + splashViewTime)) / halfTime);
    }

    logo->SetColor (splashColor);
}

void SplashCtrl::OnDestroy ()
{
    delete logo;
    logo = nullptr;

    SAFE_DELETE (splashImg);
}

HsEngine::FwBatchSprite* SplashCtrl::GetLogo () const
{
    return logo;
}

const bool SplashCtrl::IsAnimationComplete ()
{
    return drawTime > splashWaitTime + splashFadeTime + splashViewTime + splashFadeWaitTime;
}
