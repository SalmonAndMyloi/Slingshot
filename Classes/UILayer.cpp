//
//  UILayer.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "UILayer.h"

UILayer::UILayer() {
    itsLine = LineContainer::create();
    itsLine->setLineType(LINE_DRAW);
    itsLine->setVisible(false);
    addChild(itsLine,FORE_GROUND);
    itsLine->retain();
}
UILayer::~UILayer() {
    
}
UILayer * UILayer::createUILayer() {
    UILayer * _uiLayer = new UILayer;
    return _uiLayer;
}
void UILayer::update(float dt) {
    cocos2d::log("UI_Update");
    UpdateOneStep();
}
bool UILayer::onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    cocos2d::log("Hello");
    if (pTouches) {
        itsLine->setSrcTap(pTouches->getLocation());
        itsLine->setDstTap(pTouches->getLocation());
        itsLine->setVisible(true);
    }
    return true;
}
void UILayer::onTouchMoved(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    if(pTouches) {
        itsLine->setDstTap(pTouches->getLocation());
    }
}
void UILayer::onTouchEnded(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    if (pTouches)
    {
        cocos2d::Vec2 src = itsLine->getSrcTap();
        cocos2d::Vec2 dst = itsLine->getDstTap();
        cocos2d::Vec2 moveVec = src - dst;
        curMission->SetBallMovevector(moveVec);
        itsLine->setVisible(false);    }
}
void UILayer::onTouchCancelled(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
}