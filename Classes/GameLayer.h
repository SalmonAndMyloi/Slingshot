//
//  GameLayer.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__GameLayer__
#define __Slingshot__GameLayer__

#include "Mission.h"

class GameLayer : public cocos2d::Layer {
protected:
    Mission * curMission;
    int gameStatus;
    enum {
        STATUS_INIT,
        STATUS_LOADED,
        STATUS_RUNNING,
        STATUS_STOPED
    };
    enum {
        BACK_GROUND,
        GAME_SPRITE
    };
public:
    GameLayer();
    ~GameLayer();
    static GameLayer * createGameLayer();
    bool Load();
    bool Start();
    bool Stop();
    int UpdateOneStep();
};

#endif /* defined(__Slingshot__GameLayer__) */
