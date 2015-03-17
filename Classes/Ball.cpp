//
//  Ball.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "Ball.h"

Ball::Ball() {
}
Ball::~Ball() {
}
Ball * Ball::createBall() {
    Ball * ball = new Ball();
    if(ball && ball->initWithFile("Ball-3.png"))
    {
        ball->autorelease();
        return ball;
    }
    CC_SAFE_DELETE(ball);
    return NULL;
}