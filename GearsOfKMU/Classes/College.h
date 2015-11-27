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

	public:
	
	bool unlock;
	int MoneyToUnlock;
	int KnowledgeToUnlock;
	
	
	static College* setSpriteWithFile(const char * file);
	
    void setNameOfCollege(std::string, float);
    void setMajor(std::string, int, float, float timeOne, std::string, int, float, float timeSecond);
	virtual void update(float dt);

	College();
	~College();	
};

#endif // __COLLEGE_H__