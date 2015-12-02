
#include "Major.h"
#include "GameMain.h"

Major::Major(std::string name, int student)
{
    NbMaxStudent = student;
    this->name = name;
	this->setOpacity(255);
    this->schedule(schedule_selector(Major::UpdateStudent),1.0f);
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
    
cocos2d::Menu* Major::setAddSprite()
{
    auto button = cocos2d::MenuItemImage::create("Plus Button.png", "Plus Button.png", CC_CALLBACK_1(Major::AddStudent, this));
    button->setPosition(cocos2d::Vec2(40,0));
    Button = cocos2d::Menu::create(button, NULL);
    Button->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(Button, 0);
	return Button;
}

void Major::setTimeToGraduate(float time)
{
	this->TimeToGraduate = time;
}

cocos2d::Label* Major::setLabelName(std::string font, float size)
{
    auto Name = cocos2d::Label::createWithTTF(this->name, font, size);
    Name->setPosition(cocos2d::Vec2(-60, 0));
    this->addChild(Name);
    return Name;
}

cocos2d::Label* Major::setLabelStudent(std::string font, float size)
{
    this->studentLabel = cocos2d::Label::createWithTTF(std::to_string((int)student.size()) + "/" + std::to_string(NbMaxStudent), font, size);
    studentLabel->setPosition(cocos2d::Vec2(13, 0));
    this->addChild(studentLabel);
    return this->studentLabel;
}

void Major::AddStudent(Ref *pSender)
{
	auto tmp = cocos2d::Director::getInstance()->getRunningScene();
	GameMain* layer = (GameMain*)tmp->getChildren().at(1);
	if (layer != NULL)
	{
		if ((int)student.size() >= NbMaxStudent)
			return;
		if (layer->Students.size() <= 0)
			return;
		Student* stu = layer->Students.front();
		stu->startStudy = true;
		stu->setTimeToGraduate(TimeToGraduate);
		student.push_back(stu);
		layer->Students.pop_front();
	}
}

void Major::UpdateStudent(float dt)
{
   	std::list<Student*>::iterator it = student.begin();
    while (it != student.end())
    {
        if ((*it)->updateTime(dt) == true)
        {
            auto tmp = cocos2d::Director::getInstance()->getRunningScene();
            GameMain* layer = (GameMain*)tmp->getChildren().at(1);
            if (layer != NULL)
            {
                layer->AddKnowledge(1);
            }
            it = student.erase(it);
        }
        else
            ++it;
    }
}

void Major::update(float dt)
{
	studentLabel->setString(std::to_string((int)student.size()) + "/" + std::to_string(NbMaxStudent));
}
