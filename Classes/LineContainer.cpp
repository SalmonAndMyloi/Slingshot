//
//  LineContainer.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "LineContainer.h"

void LineContainer::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
    switch (line_type)
    {
        case LINE_NONE:
            break;
            
        case LINE_DRAW:
            cmd.init(_globalZOrder);
            cmd.func = CC_CALLBACK_0(LineContainer::onDraw,this,transform,flags);
            renderer->addCommand(&cmd);
            break;
    }
}
void LineContainer::onDraw(const cocos2d::Mat4 &transform, uint32_t flags)
{
    cocos2d::DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
    glLineWidth(4.0f);
    cocos2d::DrawPrimitives::drawLine(tap,pivot);
    CHECK_GL_ERROR_DEBUG();
}