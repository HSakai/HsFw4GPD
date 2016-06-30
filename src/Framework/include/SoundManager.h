#pragma once

#include "gameplay.h"

namespace HsEngine
{
    class SoundManager
    {
    public:
        static void Initialize ();
        static void Destroy ();
        static SoundManager* GetInstance ();
        void LoadCurrentBGM (const std::string bgmPath);
        unsigned int LoadSE (const std::string sePath);
        void PlayCurrentBGM ();
        void StopCurrentBGM ();
        void PlaySE (const unsigned int seNo);
        void ReleaseSE (const unsigned int seNo);
        void ReleaseAllSE ();
    private:
        explicit SoundManager ();
        ~SoundManager ();
        static SoundManager* instance;
        unsigned int loadCount;
        gameplay::AudioSource* currentBGM;

        struct LoadedSE
        {
            public:
                int LoadNo;
                std::string Path;
                gameplay::AudioSource* SE;
        };
        std::vector<LoadedSE> loadedSEList;
    };
}
