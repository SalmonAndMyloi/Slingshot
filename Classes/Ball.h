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

class Ball : public GameSprite
{
protected:
public:
    Ball();
    ~Ball();
    static Ball * createBall();
};

#endif /* defined(__Slingshot__Ball__) */
