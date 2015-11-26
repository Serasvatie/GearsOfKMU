
#include "Major.h"
#include "GameMain.h"
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
    
cocos2d::Menu* Major::setAddSprite(std::string sprite)
{
    auto button = cocos2d::MenuItemImage::create("Plus Button.png", "Plus Button.dpng", CC_CALLBACK_1(Major::AddStudent, this));
    button->setPosition(cocos2d::Vec2(20, 10));
    auto Button = cocos2d::Menu::create(button, NULL);
    Button->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(Button, 0);
    return Button;
}

cocos2d::Label* Major::setLabelName(std::string font)
{
    auto Name = cocos2d::Label::createWithTTF(this->name, font, 15.0f);
    Name->setPosition(cocos2d::Vec2(-40, 10));
    this->addChild(Name);
    return Name;
}

cocos2d::Label* Major::setLabelStudent(std::string font)
{
    this->studentLabel = cocos2d::Label::createWithTTF(std::to_string((int)student.size()) + "/" + std::to_string(NbMaxStudent), font, 15.0f);
    studentLabel->setPosition(cocos2d::Vec2(0,10));
    this->addChild(studentLabel);
    return this->studentLabel;
}

void Major::AddStudent(Ref *pSender)
{
    auto tmp = cocos2d::Director::sharedDirector()->getRunningScene();
    GameMain* layer = dynamic_cast<GameMain*>(tmp);
    Student* stu = layer->Students.front();
    student.push_back(stu);
    layer->Students.pop_front();
}