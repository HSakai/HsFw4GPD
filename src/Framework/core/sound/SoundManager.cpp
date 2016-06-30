#include "SoundManager.h"

#define DEFAULT_SE_POOL_COUNT 10

namespace HsEngine
{
    SoundManager* SoundManager::instance;

    void SoundManager::Initialize ()
    {
        instance = new SoundManager ();
    }

    void SoundManager::Destroy ()
    {
        delete instance;
        instance = nullptr;
    }

    SoundManager* SoundManager::GetInstance ()
    {
        return instance;
    }

    SoundManager::SoundManager () :
        loadCount (0),
        currentBGM (nullptr),
        loadedSEList (std::vector<LoadedSE> ())
    {
        loadedSEList.reserve (DEFAULT_SE_POOL_COUNT);
    }

    SoundManager::~SoundManager ()
    {
        if (currentBGM != nullptr)
        {
            SAFE_RELEASE (currentBGM);
            currentBGM = nullptr;
        }

        ReleaseAllSE ();
    }

    void SoundManager::LoadCurrentBGM (const std::string bgmPath)
    {
        if (currentBGM != nullptr)
        {
            SAFE_RELEASE (currentBGM);
            currentBGM = nullptr;
        }
        currentBGM = gameplay::AudioSource::create(bgmPath.c_str ());
        currentBGM->setLooped (true);
    }

    unsigned int SoundManager::LoadSE (const std::string sePath)
    {
        const int loadedCount = loadedSEList.size();
        for (int i = 0; i < loadedCount; ++i)
        {
            if (loadedSEList[i].Path.compare (sePath) != 0)
            {
                continue;
            }
            
            if (loadedSEList[i].SE == nullptr)
            {
                loadedSEList[i].SE = gameplay::AudioSource::create (sePath.c_str ());
            }
            return loadedSEList[i].LoadNo;
        }
        
        loadCount++;
        
        if (loadedCount == DEFAULT_SE_POOL_COUNT)
        {
            loadedSEList.reserve (loadedCount + 2);
        }

        LoadedSE seInfo;
        seInfo.LoadNo = loadCount;
        seInfo.Path = sePath;
        seInfo.SE = gameplay::AudioSource::create (sePath.c_str ());
        seInfo.SE->setLooped (false);
        loadedSEList.push_back (seInfo);

        return loadCount;
    }

    void SoundManager::PlayCurrentBGM ()
    {
        if (currentBGM == nullptr)
        {
            return;
        }
        currentBGM->play ();
    }

    void SoundManager::StopCurrentBGM ()
    {
        if (currentBGM == nullptr)
        {
            return;
        }
        currentBGM->stop ();
    }

    void SoundManager::PlaySE (const unsigned int seNo)
    {
        for (int i = 0, len = loadedSEList.size (); i < len; ++i)
        {
            if (loadedSEList[i].LoadNo == seNo)
            {
                if (loadedSEList[i].SE == nullptr)
                {
                    return;
                }
                loadedSEList[i].SE->play ();
            }
        }
    }

    void SoundManager::ReleaseSE (const unsigned int seNo)
    {
        for (int i = 0, len = loadedSEList.size (); i < len; ++i)
        {
            if (loadedSEList[i].LoadNo == seNo)
            {
                if (loadedSEList[i].SE == nullptr)
                {
                    return;
                }
                SAFE_RELEASE (loadedSEList[i].SE);
                loadedSEList[i].SE = nullptr;
                break;
            }
        }
    }

   void SoundManager::ReleaseAllSE ()
    {
        for (int i = 0, len = loadedSEList.size (); i < len; ++i)
        {
            if (loadedSEList[i].SE == nullptr)
            {
                continue;
            }
            SAFE_RELEASE (loadedSEList[i].SE);
            loadedSEList[i].SE = nullptr;
        }
        loadedSEList.clear ();
        loadedSEList.shrink_to_fit ();
    }
}
