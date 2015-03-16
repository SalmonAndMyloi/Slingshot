//
//  GameLayer.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__GameLayer__
#define __Slingshot__GameLayer__

#include "cocos2d.h"
#include "Mission.h"

class GameLayer : public cocos2d::Layer {
protected:
    Mission * curMission;
public:
    GameLayer();
    ~GameLayer();
    bool Load();
    bool Start();
    bool Stop();
    int UpdateOneStep();
};
#endif /* defined(__Slingshot__GameLayer__) */
