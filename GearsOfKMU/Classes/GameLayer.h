//
//  GameLayer.h
//  GearsOfKMU
//
//  Created by admin on 11/16/15.
//
//

#ifndef __GearsOfKMU__GameLayer__
#define __GearsOfKMU__GameLayer__

#include "cocos2d.h"

using namespace cocos2d;

class GameLayer : public Layer
{
private:
public:
    virtual ~GameLayer();
    GameLayer();
    
    static cocos2d::Scene* scene();
    
    virtual bool init();
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void update (float dt);
};

#endif /* defined(__GearsOfKMU__GameLayer__) */
