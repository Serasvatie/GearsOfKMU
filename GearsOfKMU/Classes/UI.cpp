
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

Label* UI::setLabelFirst(const std::string test, const std::string font, float size)
{
	first = Label::createWithTTF(test, font, size);
	auto pos = getPosition();
	first->setPosition(Vec2(pos.x, pos.y));
	return first;
}

Label* UI::setLabelSecond(const std::string test, const std::string font, float size)
{
	auto text = "+" + test + "/s";
	second = Label::createWithTTF(text, font, size);
	auto pos = getPosition();
	second->setPosition(Vec2(pos.x, pos.y));
	return first;	
}

void UI::updateLabel()
{
	
}