
#include "Major.h"

Major::Major(std::string name, int student)
{
    NbMaxStudent = student;
    this->name = name;
}

Major::~Major()
{
}

Major* Major::setSprite(std::string name, int maxStudent)
{
    auto sprite = new Major(name, maxStudent);
    if (sprite) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return sprite = nullptr;
}

cocos2d::Sprite* Major::setAddSprite(std::string sprite)
{
    //auto button = cocos2d::MenuItemImage::create("Plus Button.png", "Plus Button.png", CC_CALLBACK_1(Major::AddStudent, this));
}

bool Major::AddStudent()
{
    
}