#include "SceneSplash.h"
#include "SceneManager.h"
#include "../../common/config/SceneConst.h"
#include "SplashCtrl.h"
#include "../../../Main.h"

using namespace gameplay;

SceneSplash::SceneSplash () :
    splashCtrl (nullptr),
    HsEngine::FwScene (new SplashCtrl ())
{
}

SceneSplash::~SceneSplash ()
{
    splashCtrl = nullptr;
    GetSceneCtrl ()->OnDestroy ();
}

void SceneSplash::ProcessInitialize ()
{
    splashCtrl = static_cast<SplashCtrl*> (GetSceneCtrl ());
    splashCtrl->OnInitialize ();
}

void SceneSplash::ProcessUpdate (const uint deltaTime, const bool isEnterChild)
{
    if (splashCtrl->IsAnimationComplete ())
    {
        // シーンジャンプ
        return;
    }

    splashCtrl->OnUpdate (deltaTime, isEnterChild);
}

void SceneSplash::ProcessDraw (const bool isEnterChild)
{
    Main::getInstance ()->clear (Game::ClearFlags::CLEAR_COLOR_DEPTH, Vector4 (0, 0, 0, 1), 1.0f, 0);

    if (splashCtrl->GetLogo () == nullptr)
    {
        return;
    }

    splashCtrl->GetLogo ()->GetBatch ()->start ();
    splashCtrl->GetLogo ()->Draw ();
    splashCtrl->GetLogo ()->GetBatch ()->finish ();
}
