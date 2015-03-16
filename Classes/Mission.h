//
//  Mission.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__Mission__
#define __Slingshot__Mission__

#include "cocos2d.h"
#include "Ball.h"
#include "Target.h"
#include "LineContainer.h"

class Mission : cocos2d::Sprite {
protected:
public:
    Mission();
    ~Mission();
    static Mission * createMission();
    int ProcessOneStep();
    float GetCurTime();
    int GetCurScore();
};

#endif /* defined(__Slingshot__Mission__) */
