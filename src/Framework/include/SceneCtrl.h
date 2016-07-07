#pragma once

namespace HsEngine
{
    class SceneCtrl
    {
    public:
        virtual ~SceneCtrl ();
        virtual void OnInitialize ();
        virtual void OnBegin ();
        virtual void OnUpdate (const unsigned int deltaTime, const bool isEnterChild);
        virtual void OnKeyDown (const unsigned int keyCode);
        virtual void OnDestroy ();
    protected:
        explicit SceneCtrl ();
    };
}
