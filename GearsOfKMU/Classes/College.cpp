
#include "College.h"
#include "cocos2d.h"
#include "GameMain.h"

College::College()
{}

College::~College()
{
	CC_SAFE_RELEASE(PopupSequence);
}

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


/*
** Set Position of the class before calling this function
*/
void College::setNameOfCollege(std::string name, float size, bool unlock, int moneyToUnlock, int knowloedgeToUnlock)
{
	this->name = name;
	auto Name = cocos2d::Label::createWithTTF(this->name, FONT, size);
	Name->setPosition(cocos2d::Vec2(60, 38));
	this->unlock = unlock;
	this->MoneyToUnlock = moneyToUnlock;
	this->KnowledgeToUnlock = knowloedgeToUnlock;
	this->addChild(Name);

	Popup = cocos2d::Label::createWithTTF(TXT_POPUP, FONT, 13.0f);
	Popup->setColor(cocos2d::Color3B(247, 35, 35));
	Popup->setPosition(cocos2d::Vec2(60, 25));
	Popup->setOpacity(0);
	this->addChild(Popup, 5);
	PopupSequence = cocos2d::Sequence::create(cocos2d::FadeIn::create(0.5f),
		cocos2d::DelayTime::create(2.0f),
		cocos2d::FadeOut::create(0.5f),
		nullptr);
	PopupSequence->retain();
}

void College::setMajor(std::string majorOneName, int maxStudentOne, float sizeOne, float timeOne, std::string majorTwoName, int maxStudentSecond, float sizeSecond, float timeSecond)
{
	one = Major::setSprite(majorOneName, maxStudentOne);
	one->setAddSprite();
	one->setLabelName(FONT, sizeOne);
	one->setLabelStudent(FONT, 11.0f);
	one->setTimeToGraduate(timeOne);
	one->setPosition(cocos2d::Vec2(80, 25));
	one->setScale(one->getScale() * 0.65);
	this->addChild(one);
	two = Major::setSprite(majorTwoName, maxStudentSecond);
	two->setAddSprite();
	two->setLabelName(FONT, sizeSecond);
	two->setLabelStudent(FONT, 11.0f);
	two->setTimeToGraduate(timeSecond);
	two->setPosition(cocos2d::Vec2(80, 10));
	two->setScale(two->getScale() * 0.65);
	this->addChild(two);
	if (unlock == false)
	{
		one->Button->pause();
		two->Button->pause();
		auto but = cocos2d::MenuItemImage::create("LockCollegeZone.png", "LockCollegeZone.png", CC_CALLBACK_1(College::Unlock, this));
		but->setPosition(cocos2d::Vec2(this->getContentSize().width * 0.5, this->getContentSize().height * 0.5));
		Lock = cocos2d::Menu::create(but, NULL);
		Lock->setPosition(cocos2d::Vec2::ZERO);
		this->addChild(Lock, 0);
		LabelMoney = cocos2d::Label::createWithTTF(std::to_string(MoneyToUnlock), FONT, 11.0f);
		LabelKnowledge = cocos2d::Label::createWithTTF(std::to_string(KnowledgeToUnlock), FONT, 11.0f);
		LabelMoney->setPosition(cocos2d::Vec2(50, 35));
		LabelKnowledge->setPosition(cocos2d::Vec2(50, 15));
		this->addChild(LabelMoney);
		this->addChild(LabelKnowledge);
	}
}

void College::Unlock(Ref *pSender)
{
	auto tmp = cocos2d::Director::getInstance()->getRunningScene();
	GameMain* layer = (GameMain*)tmp->getChildren().at(1);
	if (layer != NULL)
	{
		if (layer->Money >= this->MoneyToUnlock && layer->Knowledge >= this->KnowledgeToUnlock)
		{
			layer->Money -= this->MoneyToUnlock;
			layer->Knowledge -= this->KnowledgeToUnlock;
			Lock->setPosition(cocos2d::Vec2(-250,-250));
			LabelMoney->setPosition(cocos2d::Vec2(-250,-250));
			LabelKnowledge->setPosition(cocos2d::Vec2(-250,-250));
			one->Button->resume();
			two->Button->resume();
			unlock = true;
			
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("clickbutton.mp3", false, 1.0f, 1.0f, 1.0f);
			return ;
		}
		std::stringstream os;
		os << TXT_POPUP;
		if (layer->Money < this->MoneyToUnlock)
			os << "money.";
		else
			os << "knowledge.";
		Popup->setString(os.str());
		Popup->runAction(PopupSequence->clone());
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("invalid.mp3", false, 1.0f, 1.0f, 1.0f);
	}
}

void College::update(float dt)
{
	if (unlock)
	{
		one->update(dt);
		two->update(dt);
	}
}

int College::getNumberOfStudents()
{
	int ret;
	
	ret = one->getNbStudent();
	ret += two->getNbStudent();
	
	return ret;
}

void College::Reset(bool unlock, int moneytounlock, int knowledgetounlock,
					int major1MaxStudent, float major1TimeToGraduate,
					int major2MaxStudent, float major2TimeToGraduate)
{
	this->unlock = unlock;
	if (unlock == false)
	{
		Lock->setVisible(true);
		LabelKnowledge->setVisible(true);
		LabelMoney->setVisible(true);
	}
	this->MoneyToUnlock = moneytounlock;
	this->KnowledgeToUnlock = knowledgetounlock;
	one->Reset(major1MaxStudent, major1TimeToGraduate);
	two->Reset(major2MaxStudent, major2TimeToGraduate);
}
