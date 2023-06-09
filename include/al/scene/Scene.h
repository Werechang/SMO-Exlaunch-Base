#pragma once

#include "SceneInitInfo.h"
#include "al/actor/LiveActorKit.h"
#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraDirector.h"
#include "al/scene/SceneObjHolder.h"
#include <al/nerve/NerveExecutor.h>

namespace al
{

    class GraphicsInitArg;

    class Scene : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseCamera, public al::IUseSceneObjHolder
    {
    public:
        Scene(const char *);

        virtual ~Scene();
        virtual void init(const al::SceneInitInfo &);
        virtual void appear();
        virtual void kill();
        virtual void movement();
        virtual void control();
        virtual void drawMain();
        virtual void drawSub();
        virtual al::AudioKeeper* getAudioKeeper();
        virtual al::SceneObjHolder* getSceneObjHolder();
        virtual al::CameraDirector* getCameraDirector();

        void initDrawSystemInfo(al::SceneInitInfo const&);

        void initLiveActorKitWithGraphics(al::GraphicsInitArg const &, al::SceneInitInfo const &, int, int, int);

        bool mIsAlive;
        sead::FixedSafeString<0x40> mName;
        void* mStageResourceKeeper;
        LiveActorKit* mLiveActorKit;
        LayoutKit* mLayoutKit;
        SceneObjHolder* mSceneObjHolder;
        void* mSceneStopCtrl;
        void* mSceneMsgCtrl;
        void* mScreenCoverCtrl;
        AudioDirector* mAudioDirector;
        AudioKeeper* mAudioKeeper;
        NerveKeeper* mNerveKeeper;
    };
};