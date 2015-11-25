#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Student.h"
#include "UI.h"

class GameMain : public cocos2d::Layer
{
private:
    cocos2d::Sprite *logo;
    cocos2d::Sprite *background;
    
    UI* NBStudent;
    UI* NBMoney;
    UI* NBKnowledge;
    
    std::list<Student*> NumberOfStudent;
    float StudentBySec;
    
    int Money;
    float MoneyBySecond;
    
    int Knowledge;
    
    void UpgradeMenu(Ref *pSender);
    void StatisticMenu(Ref *pSender);
    void ResetMenu(Ref *pSender);
    
public:
    virtual ~GameMain();
    GameMain();
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void update (float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameMain);
};

#endif // __HELLOWORLD_SCENE_H__
