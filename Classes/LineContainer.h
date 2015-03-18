//
//  LineContainer.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#ifndef __Slingshot__LineContainer__
#define __Slingshot__LineContainer__

enum{
    LINE_NONE,
    LINE_DRAW
};

class LineContainer : public cocos2d::Node
{
protected:
    CC_SYNTHESIZE(cocos2d::Vec2, _srcTap, SrcTap);
    CC_SYNTHESIZE(cocos2d::Vec2, _dstTap, DstTap);
    CC_SYNTHESIZE(int, line_type, LineType);
    cocos2d::CustomCommand cmd;
public:
    CREATE_FUNC(LineContainer);
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
};

#endif /* defined(__Slingshot__LineContainer__) */
