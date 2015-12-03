//
//  ResetLayer.h
//  GearsOfKMU
//
//  Created by admin on 12/3/15.
//
//

#ifndef __GearsOfKMU__ResetLayer__
#define __GearsOfKMU__ResetLayer__

#include <stdio.h>

class ResetLayer : public cocos2d::LayerColor
{
private:
    cocos2d::Label* txt;
    cocos2d::Menu* Yes;
    cocos2d::Menu* No;
    cocos2d::MoveTo* In;
    cocos2d::MoveTo* Out;
public:
    static ResetLayer* create();
    virtual bool init();
    void YesFunction();
    void NoFunction();
    
    ResetLayer();
    ~ResetLayer();
};

#endif /* defined(__GearsOfKMU__ResetLayer__) */
