//
//  UILayer.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__UILayer__
#define __Slingshot__UILayer__

#include "GameLayer.h"
#include "LineContainer.h"

class UILayer : public GameLayer {
protected:
    LineContainer * itsLine;
public:
    UILayer();
    ~UILayer();
    static UILayer * createUILayer();
    virtual void update(float);
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
};

#endif /* defined(__Slingshot__UILayer__) */
