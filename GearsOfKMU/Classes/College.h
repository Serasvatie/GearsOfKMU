#ifndef __COLLEGE_H__
#define __COLLEGE_H__

#include <string>
#include "Major.h"
#include "cocos2d.h"

class College : public cocos2d::Sprite
{
	private:
	Major *one;
	Major *two;
	std::string name;
    bool unlock;
    int MoneyToUnlock;
    int KnowledgeToUnlock;
    cocos2d::Menu* Lock;
    cocos2d::Label* LabelMoney;
    cocos2d::Label* LabelKnowledge;
    
	public:
	
	static College* setSpriteWithFile(const char * file);
	
    void Unlock(Ref *pSender);
    void setNameOfCollege(std::string, float, bool unlock, int moneyToUnlock, int knowledgeToUnlock);
    void setMajor(std::string, int, float, float timeOne, std::string, int, float, float timeSecond);
	virtual void update(float dt);

	College();
	~College();	
};

#endif // __COLLEGE_H__