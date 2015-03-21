//
//  UILayer.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "UILayer.h"

UILayer::UILayer() {
    
}
UILayer::~UILayer() {
    
}
UILayer * UILayer::createUILayer() {
    UILayer * _uiLayer = new UILayer;
    return _uiLayer;
}
void UILayer::update(float dt) {
    UpdateOneStep();
}
bool UILayer::onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    if (pTouches) {
        if(curMission->GetStatus() == Mission::STATUS::RUNNING_BALL_STOP) {
            tapSrc = pTouches->getLocation();
        }
    }
    return true;
}
void UILayer::onTouchMoved(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    if(pTouches) {
        if(curMission->GetStatus() == Mission::STATUS::RUNNING_BALL_STOP) {
            tapDst = pTouches->getLocation();
            curMission->SetBallMovevector(tapSrc - tapDst);
        }
    }
}
void UILayer::onTouchEnded(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    if (pTouches)
    {
        if(curMission->GetStatus() == Mission::STATUS::RUNNING_BALL_STOP) {
            curMission->LaunchBall();
        }
    }
}
void UILayer::onTouchCancelled(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
}