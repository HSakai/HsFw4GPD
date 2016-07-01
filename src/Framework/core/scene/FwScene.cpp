#include "FwScene.h"
#include "SceneManager.h"
#include "gameplay.h"

namespace HsEngine
{
    FwScene::FwScene () : childScene (nullptr)
    {
    }

    FwScene::~FwScene ()
    {
        if (childScene != nullptr)
        {
            delete childScene;
            childScene = nullptr;
        }
    }

    FwScene* FwScene::operator=(FwScene* scene)
    {
        return scene;
    }

    void FwScene::OnKeyDown (const int key)
    {
        switch (key)
        {
            case gameplay::Keyboard::KEY_ESCAPE:
                break;
        }
    }

    void FwScene::ProcessInitialize ()
    {
    }

    void FwScene::ProcessBegin ()
    {
    }

    void FwScene::ProcessUpdate (const uint deltaTime, const bool isEnterChild)
    {
    }

    void FwScene::ProcessDraw (const bool isEnterChild)
    {
    }

    bool FwScene::OnDrawNode (gameplay::Node* node)
    {
        return true;
    }

    void FwScene::JumpScene (const int sceneId)
    {
        SceneManager::GetInstance ()->ReserveNextScene (sceneId);
    }

    void FwScene::CallScene (const int sceneId)
    {
        SceneManager::GetInstance ()->ReserveReplaceScene (sceneId);
    }

    void FwScene::ReturnScene ()
    {
        SceneManager::GetInstance ()->ReserveReturnScene ();
    }

    void FwScene::ReturnToRootScene ()
    {
        SceneManager::GetInstance ()->ReserveReturnToRootScene ();
    }

    FwScene* FwScene::GetChild ()
    {
        return childScene;
    }

    void FwScene::SetChild (FwScene* scene)
    {
#ifdef DEBUG
        if (childScene != nullptr)
        {
            const std::string logText = "already set child !!";
            PutLog (logText);
        }
#endif
        if (scene == nullptr)
        {
#ifdef DEBUG
            const std::string logText = "scene is nullptr !! so, return this method.";
            PutLog (logText);
#endif
            return;
        }

        if (childScene != nullptr)
        {
            DestroyChild ();
        }

        childScene = scene;
    }

    void FwScene::DestroyChild ()
    {
        if (childScene == nullptr)
        {
            return;
        }

        delete childScene;
        childScene = nullptr;
    }
}
