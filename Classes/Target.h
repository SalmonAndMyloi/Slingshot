//
//  Target.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__Target__
#define __Slingshot__Target__


#include "GameSprite.h"

class Target : public GameSprite
{
protected:
    int type;
public:
    Target();
    Target(int);
    ~Target();
    static Target * createWithTypeNumber(int);
};


#endif /* defined(__Slingshot__Target__) */
