//
//  ResetLayer.cpp
//  GearsOfKMU
//
//  Created by admin on 12/3/15.
//
//

#include "ResetLayer.h"
#include "GameMain.h"

ResetLayer::ResetLayer()
{
}

ResetLayer::~ResetLayer()
{
	CC_SAFE_RELEASE(In);
	CC_SAFE_RELEASE(Out);
}

bool ResetLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !LayerColor::initWithColor(cocos2d::Color4B(20,20,20,230)))
	{
		return false;
	}

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	this->setContentSize(visibleSize);

	initialPos = cocos2d::Vec3(-visibleSize.width, 0, 0);

	this->setColor(cocos2d::Color3B(100, 100, 100));
	this->setPosition(cocos2d::Vec2(initialPos.x, initialPos.y));

	txt = cocos2d::Label::createWithTTF("Are you sure you want to reset ?", FONT, 20.0f);
	txt->setPosition(cocos2d::Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.7f));
	this->addChild(txt);
	
	auto yes = cocos2d::MenuItemImage::create("Yes.png", "Yes.png", CC_CALLBACK_1(ResetLayer::YesFunction, this));
	auto no = cocos2d::MenuItemImage::create("No.png", "No.png", CC_CALLBACK_1(ResetLayer::NoFunction, this));
	yes->setPosition(cocos2d::Vec2(visibleSize.width * 0.25, visibleSize.height * 0.35));
	no->setPosition(cocos2d::Vec2(visibleSize.width * 0.75, visibleSize.height * 0.35));
	yes->setScale(yes->getScale() * 2);
	no->setScale(no->getScale() * 2);
	Yes = cocos2d::Menu::create(yes, NULL);
	Yes->setPosition(cocos2d::Vec2::ZERO);
	No = cocos2d::Menu::create(no, NULL);
	No->setPosition(cocos2d::Vec2::ZERO);
	this->addChild(Yes);
	this->addChild(No);

	In = cocos2d::MoveTo::create(0.2f, cocos2d::Vec3(origin.x, origin.y, 0));
	In->retain();
	Out = cocos2d::MoveTo::create(0.2f, cocos2d::Vec3(initialPos));
	Out->retain();
	return true;
}

void ResetLayer::update(float dt)
{
}

void ResetLayer::YesFunction(cocos2d::Ref * pSender)
{
	auto tmp = cocos2d::Director::getInstance()->getRunningScene();
	auto main = (GameMain*)tmp->getChildren().at(1);
	main->TrueReset();
	this->Hide();
}

void ResetLayer::NoFunction(cocos2d::Ref * pSender)
{
	this->Hide();
}

void ResetLayer::Show()
{
	this->runAction(In->clone());
}

void ResetLayer::Hide()
{
	this->runAction(Out->clone());
}
