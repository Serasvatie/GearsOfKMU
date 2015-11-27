
#include "College.h"

College::College()
{}

College::~College()
{}

College* College::setSpriteWithFile(const char *file)
{
    auto sprite = new College();
    if (sprite && sprite->initWithFile(file)) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return sprite = nullptr;
}

void College::setNameOfCollege(std::string name, float size)
{
    this->name = name;
    auto Name = cocos2d::Label::createWithTTF(this->name, "fonts/arial.ttf", size);
    Name->setPosition(cocos2d::Vec2(60, 38));
    this->addChild(Name);
}

void College::setMajor(std::string majorOneName, int maxStudentOne, float sizeOne, float timeOne, std::string majorTwoName, int maxStudentSecond, float sizeSecond, float timeSecond)
{
	one = Major::setSprite(majorOneName, maxStudentOne);
	one->setAddSprite();
	one->setLabelName("fonts/arial.ttf", sizeOne);
	one->setLabelStudent("fonts/arial.ttf", 11.0f);
	one->setTimeToGraduate(timeOne);
	one->setPosition(cocos2d::Vec2(80, 25));
	one->setScale(one->getScale() * 0.65);
	this->addChild(one);
	two = Major::setSprite(majorTwoName, maxStudentSecond);
	two->setAddSprite();
	two->setLabelName("fonts/arial.ttf", sizeSecond);
	two->setLabelStudent("fonts/arial.ttf", 11.0f);
	two->setTimeToGraduate(timeSecond);
	two->setPosition(cocos2d::Vec2(80, 10));
	two->setScale(two->getScale() * 0.65);
	this->addChild(two);
}

void College::update(float dt)
{
	one->update(dt);
	two->update(dt);
}

