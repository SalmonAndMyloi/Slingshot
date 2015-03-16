//
//  Ball.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__Ball__
#define __Slingshot__Ball__


#include "GameSprite.h"

class PlayerBall : public GameSprite
{
protected:
public:
    PlayerBall()
    {}
    ~PlayerBall()
    {}
    static PlayerBall * createWithType(int type) {
        PlayerBall * ball = new PlayerBall();
        if(ball && ball->initWithFile("Ball-3.png"))
        {
            ball->autorelease();
            return ball;
        }
        CC_SAFE_DELETE(ball);
        return NULL;
    }
};

#endif /* defined(__Slingshot__Ball__) */
