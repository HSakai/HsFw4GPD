#include "SceneFactory.h"
#include "../config/SceneConst.h"
#include "../../scene/splash/SceneSplash.h"

namespace HsEngine
{
    FwScene* SceneFactory::CreateScene (const int sceneId)
    {
        switch (sceneId)
        {
            case SCENE_SPLASH:
                return new SceneSplash ();
        }
        return nullptr;
    }
}
