#include "SceneSplash.h"
#include "SceneManager.h"
#include "../../../Main.h"

using namespace gameplay;

SceneSplash::SceneSplash () :
    drawTime (0),
    splashWaitTime (500),
    splashFadeTime (2000),
    splashViewTime (1000),
    splashImg (SpriteBatch::create ("res/logo_powered_white.png")),
    splashColor (Vector4::one ()),
    HsEngine::FwScene ()
{
    splashColor.w = 0;
}

SceneSplash::~SceneSplash ()
{
    SAFE_DELETE (splashImg);
}

void SceneSplash::ProcessUpdate (const uint deltaTime, const bool isEnterChild)
{
    drawTime += deltaTime;
    if (drawTime > splashWaitTime + splashFadeTime + splashViewTime)
    {
        // シーンチェンジ
        splashColor.w = 0;
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
}

void SceneSplash::ProcessDraw (const bool isEnterChild)
{
    Main::getInstance ()->clear (Game::ClearFlags::CLEAR_COLOR_DEPTH, Vector4 (0, 0, 0, 1), 1.0f, 0);
    splashImg->start ();
    splashImg->draw (Main::getInstance ()->getWidth() * 0.5f, Main::getInstance ()->getHeight() * 0.5f,
        0.0f, 512.0f, 512.0f, 0.0f, 1.0f, 1.0f, 0.0f, splashColor, true);
    splashImg->finish ();
}
