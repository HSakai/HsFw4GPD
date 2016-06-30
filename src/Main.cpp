#include "Main.h"
#include "SceneManager.h"
#include "SoundManager.h"

// Declare our game instance
Main game;

Main::Main()
    : sceneMgr (nullptr)
{
}

void Main::initialize()
{
    setViewport (Rectangle (0, 0, getWidth (), getHeight ()));
    HsEngine::SceneManager::Initialize ();
    HsEngine::SoundManager::Initialize ();
    sceneMgr = HsEngine::SceneManager::GetInstance ();
    sceneMgr->ReserveNextScene (HsEngine::SceneManager::ROOT_SCENE_ID);
}

void Main::finalize()
{
    HsEngine::SceneManager::Destroy ();
    HsEngine::SoundManager::Destroy ();
}

void Main::update(float elapsedTime)
{
    sceneMgr->OnStartOfFrame ();
    
    const unsigned int deltaTime = (int)elapsedTime;
    sceneMgr->OnUpdate (deltaTime);
}

void Main::render(float elapsedTime)
{
    clear (CLEAR_COLOR_DEPTH, 0.1f, 0.1f, 0.3f, 1.0f, 1.0f, 0);
    sceneMgr->OnDraw ();
}

bool Main::drawScene(Node* node)
{
    return true;
}

void Main::keyEvent(Keyboard::KeyEvent evt, int key)
{
    if (evt == Keyboard::KEY_PRESS)
    {
        switch (key)
        {
        case Keyboard::KEY_ESCAPE:
            exit ();
            break;
        }
    }
}

void Main::touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex)
{
    switch (evt)
    {
    case Touch::TOUCH_PRESS:
        break;
    case Touch::TOUCH_RELEASE:
        break;
    case Touch::TOUCH_MOVE:
        break;
    };
}
