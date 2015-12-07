
#include "UI.h"

UI::UI()
{
	
}

UI::~UI()
{
	
}

UI* UI::setSpriteWithFile(const char *file)
{
	auto sprite = new UI();
	if (sprite && sprite->initWithFile(file)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return sprite = nullptr;
}

cocos2d::Label* UI::setLabelFirst(const std::string test, const std::string font, float size)
{
	this->first = cocos2d::Label::createWithTTF(test, font, size);
	auto pos = this->getPosition();
    this->first->setPosition(cocos2d::Vec2(40, 17));
    this->addChild(first);
	return first;
}

cocos2d::Label* UI::setLabelSecond(const std::string test, const std::string font, float size)
{
	auto text = "+" + test + "/s";
	second = cocos2d::Label::createWithTTF(text, font, size);
	auto pos = this->getPosition();
    second->setPosition(cocos2d::Vec2(80, 14));
    this->addChild(second);
	return first;	
}

void UI::updateLabel(int first, float second)
{
    this->first->setString(std::to_string(first));

    std::ostringstream buff;
    buff << second;
    std::string text = "+" + buff.str() + "/s";
    this->second->setString(text);

}

void UI::updateLabel(int first)
{
    this->first->setString(std::to_string(first));
}