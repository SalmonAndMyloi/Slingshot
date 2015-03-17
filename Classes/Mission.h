//
//  Mission.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__Mission__
#define __Slingshot__Mission__

#include "GameSprite.h"
#include "Ball.h"
#include "Target.h"
#include "LineContainer.h"

class MissionGenerator;

typedef std::vector<GameSprite*> GameSpriteArray;
typedef std::vector<Target*> TargetArray;
//typedef std::vector<GameSpriteArray*> GameSpriteArrayArray;

class Mission : public cocos2d::Sprite {
protected:
    Ball * itsBall;
    int itsTime;
    int itsScore;
    float itsGravityFactor;
    float itsAirResistanceFactor;
    cocos2d::Vec2 itsBallStartPosition;
    GameSpriteArray itsMovingSpriteArray;
    TargetArray itsTargetArray;
protected:
    Mission();
    ~Mission();
    void initMission();
    bool CheckPositionForOutOfBound(cocos2d::Vec2);
public:
    static Mission * createMission();
    int GetCurTime();
    int GetCurScore();
    Ball * GetBall();
    bool SetBallMovevector(cocos2d::Vec2);
    int UpdateAllObjectPosition();
    friend MissionGenerator;
};

#endif /* defined(__Slingshot__Mission__) */
