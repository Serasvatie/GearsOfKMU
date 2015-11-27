#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__

#include "cocos2d.h"
#include "Student.h"
#include "College.h"
#include "UI.h"

class GameMain : public cocos2d::Layer
{
private:
    cocos2d::Sprite *logo;
    cocos2d::Sprite *background;
    
    UI* NBStudent;
    UI* NBMoney;
    UI* NBKnowledge;
    
    College* Engineering;
	College* Medecine;
	College* Education;
	College* Social;
	College* Natural;
	College* Music;

    float second;
    float deltaTime;
    
    float StudentBySec;
    float StudentTmp;
    
    int Money;
    float MoneyBySecond;
    float MoneyTmp;
    
    int Knowledge;
    
    void UpgradeMenu(Ref *pSender);
    void StatisticMenu(Ref *pSender);
    void ResetMenu(Ref *pSender);

	void updateRessources();
	void updateAffRessources();
	void updateCollege(float dt);

public:
    virtual ~GameMain();
    GameMain();
    
    static cocos2d::Scene* createScene();
    
    std::list<Student*> Students;
    
    virtual bool init();
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void update (float dt);

	void AddKnowledge(int addvalue);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameMain);
};

#endif // __GAMEMAIN_H__
