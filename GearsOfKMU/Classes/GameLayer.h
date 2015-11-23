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
#include <list>
#include "Student.h"

USING_NS_CC;

class GameLayer : public Layer
{
private:
    
    Sprite *logo;
    
    std::list<Student*> NumberOfStudent;
    float StudentBySec;
    
    int Money;
    float MoneyBySecond;
    
    int Knowledge;
    
    void UpgradeMenu(Ref *pSender);
    void StatisticMenu(Ref *pSender);
    void ResetMenu(Ref *pSender);
    
public:
    virtual ~GameLayer();
    GameLayer();
    
    static cocos2d::Scene* scene();
    
    virtual bool init();
    
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void update (float dt);
};

#endif /* defined(__GearsOfKMU__GameLayer__) */
