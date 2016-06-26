#include "Main.h"
#include "SceneManager.h"

// Declare our game instance
Main game;

Main::Main()
{
}

void Main::initialize()
{
    HsEngine::SceneManager::Initialize ();
}

void Main::finalize()
{
}

void Main::update(float elapsedTime)
{
}

void Main::render(float elapsedTime)
{
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
            exit();
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
