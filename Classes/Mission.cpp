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
Ball * Mission::GetBall() {
    return itsBall;
}
bool Mission::SetBallMovevector(cocos2d::Vec2 moveVec) {
    if(itsBall->getIsMoving()) //if the ball is moving cancel it
        return false;
    itsBall->setMoveVector(moveVec);
    itsBall->setIsMoving(true);
    return true;
}