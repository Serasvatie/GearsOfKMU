#include <sstream>
#include "cocos2d.h"

class UI : public cocos2d::Sprite
{
	private:
		cocos2d::Label* first;
		cocos2d::Label* second;
	public:
	
	UI();
	virtual ~UI();
	
	static UI* setSpriteWithFile(const char *file);
	
	cocos2d::Label* setLabelFirst(const std::string test, const std::string font, float size);
	cocos2d::Label* setLabelSecond(const std::string test, const std::string font, float size);
	
    void updateLabel(int, float);
    void updateLabel(int);
};