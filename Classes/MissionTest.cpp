//
//  MissionTest.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "MissionTest.h"

MissionTest::MissionTest() {
    this->initMission();
    //temp values
    cocos2d::Vec2 moveVecForTesting(1,1);
    //init local values
    itsTime = 0;
    itsScore = 0;
    itsGravityFactor = 0.98;
    itsAirResistanceFactor = -0.99;
    itsBallStartPosition = cocos2d::Vec2(100,200);
    
    //init ball
    itsBall = Ball::createBall();
    itsMovingSpriteArray.push_back(itsBall);
    itsBall->setPosition(itsBallStartPosition);
    itsBall->setIsMoving(false);
    itsBall->setMoveVector(cocos2d::Vec2::ZERO);
    addChild(itsBall);
    itsBall->retain();
    
    //init targets random
    for(int i=0; i<5; i++) {
        Target * _tempTarget = Target::createWithTypeNumber(0);
        _tempTarget->setPosition(cocos2d::Vec2(100 + i*100, 100 + i*100));
        _tempTarget->setIsMoving(true);
        _tempTarget->setMoveVector(moveVecForTesting);
        addChild(_tempTarget);
        _tempTarget->retain();
        itsMovingSpriteArray.push_back(_tempTarget);
    }
}
MissionTest::~MissionTest() {
}
MissionTest * MissionTest::createMissionTest() {
    auto * test = new MissionTest();
    if(test && test->initWithFile("board10.png") )
    {
        test->autorelease();
        return test;
    }
    CC_SAFE_DELETE(test);
    return NULL;
}