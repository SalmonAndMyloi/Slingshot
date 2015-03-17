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
    addChild(itsLine,GAME_SPRITE);
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
}bool UILayer::onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    //터치가 볼에 닿았을 경우 라인 콘테이너의 시작점과 끝점을 선정, 그 후 라인 타입(라인을 그려도 된다고 지시)을 바꾼다.
    if (pTouches)
    {
        Ball * ball = curMission->GetBall();
        float dx = ball->getPosition().x - pTouches->getLocation().x;
        float dy = ball->getPosition().y - pTouches->getLocation().y;
        
        if (dx*dx + dy*dy <= pow(ball->Radius(), 2))
        {
            itsLine->setTap(ball->getPosition());
            itsLine->setPivot(ball->getPosition());
            itsLine->setLineType(LINE_DRAW);
            return true;
        }
    }
    return false;
}
void UILayer::onTouchMoved(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    cocos2d::log("onTouchMoved");
    //그릴 라인의 끝부분을 터치가 이루어지는 곳으로 설정(draw메서드는 자동으로 호출된다.)
    itsLine->setPivot(pTouches->getLocation());
}
void UILayer::onTouchEnded(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    cocos2d::log("onTouchEnded");
    if (pTouches)
    {
        //터치를 끌은 만큼 이동 벡터를 만들고 볼의 이동벡터에 적용시킨다. 이후 볼은 update매서드에 의해 자동으로 이동함, 그리고 라인 콘테이너를 비활성으로 만듬
        Ball * ball = curMission->GetBall();
        cocos2d::Vec2 tap = itsLine->getTap();
        cocos2d::Vec2 pivot = pTouches->getLocation();
        ball->setMoveVector(tap-pivot);
        ball->setIsMoving(true);
        itsLine->setLineType(LINE_NONE);
    }
    
}
void UILayer::onTouchCancelled(cocos2d::Touch *pTouches,cocos2d::Event *unused_event) {
    cocos2d::log("onTouchCancelled");
}