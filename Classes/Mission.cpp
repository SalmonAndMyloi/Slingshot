//
//  Mission.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "Mission.h"

Mission::Mission() {
    
}
Mission::~Mission() {
    
}
void Mission::initMission() {
    itsTime = 0;
    itsScore = 0;
    itsBallStartPosition = cocos2d::Vec2::ZERO;
    itsBall = Ball::createBall();
    addChild(itsBall);
    itsBall->setPosition(itsBallStartPosition);
    itsBall->setIsMoving(false);
    itsStatus = RUNNING_BALL_STOP;
}
Mission * Mission::createMission() {
    Mission * _mission = new Mission();
    _mission->initMission();
    return _mission;
}
int Mission::UpdateAllObjectPosition() {
    int size = (int) itsMovingSpriteArray.size();
    for(int i=0; i<size; ++i) {
        GameSprite * moveObject = itsMovingSpriteArray[i];
        if(moveObject->getIsMoving() == false)
            continue;
        moveObject->Move();
        if( CheckPositionForOutOfBound(moveObject->getPosition())) {
            moveObject->setPosition(cocos2d::Vec2(itsBallStartPosition));
            moveObject->setIsMoving(false);
            if(moveObject == itsBall) {
                itsStatus = STATUS::RUNNING_BALL_STOP;
            }
        }
    }
    return 0;
}
bool Mission::CheckPositionForOutOfBound(cocos2d::Vec2 _pos) {
    auto size = this->getBoundingBox().size;
    if(_pos.x<0 || _pos.y<0 || _pos.x > size.width || _pos.y > size.height)
        return true;
    return false;
}
Mission::STATUS Mission::GetStatus() {
    return itsStatus;
}
bool Mission::SetBallMovevector(cocos2d::Vec2 moveVec) {
    if(itsStatus == STATUS::RUNNING_BALL_STOP) {
        itsBall->setMoveVector(moveVec);
        return true;
    }
    return false;
}
bool Mission::LaunchBall() {
    if(itsStatus == STATUS::RUNNING_BALL_STOP) {
        itsBall->setIsMoving(true);
        itsStatus = STATUS::RUNNING_BALL_MOVE;
        return true;
    }
    return false;
}