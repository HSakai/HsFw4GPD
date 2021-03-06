/*
 * ゲーム設定
 */
#include "Config.h"
#include "Utils.h"

namespace HsEngine
{
    const char* GAME_TITLE = "Engineテスト";

    const char TARGET_FPS = 60;

    const short WINDOW_WIDTH = 960;

    const short WINDOW_HEIGHT = 640;

    // Escとqキーで一旦終了させてみる
    const int EXIT_KEYCODES[] = { gameplay::Keybord::KEY_ESCAPE };

    const unsigned EXIT_KEYCODE_LEN = 2;
}
