#pragma once

#include "gameplay.h"

using namespace gameplay;

namespace HsEngine
{
    class SceneManager;
}

/**
 * Main game class.
 */
class Main: public Game
{
public:

    /**
     * Constructor.
     */
    Main();

    /**
     * @see Game::keyEvent
     */
	void keyEvent(Keyboard::KeyEvent evt, int key);
	
    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime) override;

    /**
     * @see Game::render
     */
    void render(float elapsedTime) override;

private:
    HsEngine::SceneManager* sceneMgr;
};
