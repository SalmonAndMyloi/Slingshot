//
//  Target.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "Target.h"

Target::Target() {
}
Target::Target(int _type) {
    type = _type;
}
Target::~Target() {
    
}Target * Target::createWithTypeNumber(int type) {
    auto * candy = new Target(type);
    if(candy && candy->initWithFile("Ball-3.png"))
    {
        candy->autorelease();
        return candy;
    }
    CC_SAFE_DELETE(candy);
    return NULL;
}