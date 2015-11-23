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
	
	Major one;
	Major two;
	
	College();
	~College();	
};