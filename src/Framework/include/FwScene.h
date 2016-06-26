/*
 * シーンのベースとなるIF
 */
#pragma once

#include "gameplay.h"
#include "Utils.h"

namespace HsEngine
{
    class FwScene
    {
    public:
        FwScene ();
        virtual ~FwScene ();
        FwScene* operator=(FwScene* scene);
        virtual void OnKeyDown (const int key);
        virtual void ProcessInitialize ();
        virtual void ProcessBegin ();
        virtual void ProcessUpdate (const uint deltaTime, const bool isEnterChild);
        virtual void ProcessDraw (const bool isEnterChild);
        FwScene* GetChild ();
        void SetChild (FwScene* scene);
        void DestroyChild ();
    protected:
        void JumpScene (const int sceneId);
        void CallScene (const int sceneId);
        void ReturnScene ();
        void ReturnToRootScene ();
    private:
        FwScene* childScene;
    };
}
