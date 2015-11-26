
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

void College::setNameOfCollege(std::string name)
{
    this->name = name;
    auto Name = cocos2d::Label::createWithTTF("name", "fonts/arial.ttf", 15.0f);
    Name->setPosition(cocos2d::Vec2(75, 125));
    this->addChild(Name);
}

void College::setMajor(std::string majorOneName, int maxStudentOne, std::string majorTwoName, int maxStudentSecond)
{
    one = Major::setSprite(majorOneName, maxStudentOne);
    one->setPosition(cocos2d::Vec2(40,40));
    this->addChild(one);
    two = Major::setSprite(majorTwoName, maxStudentSecond);
    two->setPosition(cocos2d::Vec2(80,80));
    this->addChild(two);
}