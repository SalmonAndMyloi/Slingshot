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
public:
    enum STATUS {
        RUNNING_BALL_STOP,
        RUNNING_BALL_MOVE,
        MISSION_CLEAR
    };
protected:
    typedef std::vector<GameSprite*> GameSpriteArray;
    typedef std::vector<Target*> TargetArray;
    CC_SYNTHESIZE_READONLY(int, itsTime, curTime);
    CC_SYNTHESIZE_READONLY(int, itsScore, curScore);
    CC_SYNTHESIZE_READONLY(Mission::STATUS, itsStatus, curStatus);
    CC_SYNTHESIZE_READONLY(float, itsGravityFactor, GravityFactor);
    CC_SYNTHESIZE_READONLY(float, itsAirResistanceFactor, AirResistanceFactor);
    Ball * itsBall;
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
    STATUS GetStatus();
    bool SetBallMovevector(cocos2d::Vec2);
    bool LaunchBall();
    int UpdateAllObjectPosition();
    friend MissionGenerator;
};

#endif /* defined(__Slingshot__Mission__) */
