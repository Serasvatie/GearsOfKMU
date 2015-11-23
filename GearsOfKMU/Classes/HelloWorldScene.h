#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Student.h"

class HelloWorld : public cocos2d::Layer
{
    cocos2d::Sprite *logo;
    
    std::list<Student*> NumberOfStudent;
    float StudentBySec;
    
    int Money;
    float MoneyBySecond;
    
    int Knowledge;
    
    void UpgradeMenu(Ref *pSender);
    void StatisticMenu(Ref *pSender);
    void ResetMenu(Ref *pSender);
    
public:
    virtual ~HelloWorld();
    HelloWorld();
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void update (float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
