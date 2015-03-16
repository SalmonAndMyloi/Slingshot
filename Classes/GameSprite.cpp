//
//  GameSprite.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "GameSprite.h"

void GameSprite::Move()
{
    cocos2d::Vec2 nextPosition = getPosition() + getMoveVector();
    this->setPosition(nextPosition);
}
