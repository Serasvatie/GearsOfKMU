
#include "cocos2d.h"

using namespace cocos2d;

class UI : public cocos2d::Sprite
{
	private:
		Label* first;
		Label* second;
	public:
	
	UI();
	virtual ~UI();
	
	static UI* setSpriteWithFile(const char *file);
	
	Label* setLabelFirst(const std::string test, const std::string font, float size);
	Label* setLabelSecond(const std::string test, const std::string font, float size);
	
	void updateLabel();
};