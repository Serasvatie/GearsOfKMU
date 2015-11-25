#include <string>
#include "Major.h"
#include "cocos2d.h"

class College : public cocos2d::Sprite
{
	private:
	
	public:
	
	bool unlock;
	int MoneyToUnlock;
	int KnowledgeToUnlock;
	
	std::string name;
	
	static College* setSpriteWithFile(const char * file);
	
    void setNameOfCollege(std::string);
    void setMajor(std::string, int, std::string, int);
	Major *one;
	Major *two;
	
	College();
	~College();	
};