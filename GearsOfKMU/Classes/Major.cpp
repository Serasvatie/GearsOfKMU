
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
    auto button = cocos2d::MenuItemImage::create("Plus Button.png", "Plus Button.png", CC_CALLBACK_1(Major::AddStudent, this));
    button->setPosition(Vec2(20, 10));
    auto Button = Menu::create(button, NULL);
    Button->setPosition(Vec2::ZERO);
    this->addChild(Button, 0);
    return Button;
}

cocos2d::Label* setLabelName(std::string font)
{
    auto Name = cocos2d::Label::createWithTTF(name, font, "15.0f");
    Name->setPosition(cocos2d::Vec2(-40, 10));
    return Name;
}

cocos2d::Label* setLabelStudent(std::string font)
{
    this->studentLabel = cocos2d::Label::createWithTTF(student.size() + "/" + NbMaxStudent, font, "15.0f");
    studentLabel->setPosition(cocos2d::Vec2(0,10));
    return this->student;
}

bool Major::AddStudent(Student *tmp)
{
    student.add(tmp);
    return true;
}