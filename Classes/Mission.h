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

class Mission : public cocos2d::Sprite {
protected:
    typedef std::vector<GameSprite*> GameSpriteArray;
    typedef std::vector<Target*> TargetArray;
    typedef int Status;
protected:
    CC_SYNTHESIZE_READONLY(int, itsTime, curTime);
    CC_SYNTHESIZE_READONLY(int, itsScore, curScore);
    Ball * itsBall;
    float itsGravityFactor;
    float itsAirResistanceFactor;
    cocos2d::Vec2 itsBallStartPosition;
    GameSpriteArray itsMovingSpriteArray;
    TargetArray itsTargetArray;
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
