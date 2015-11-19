//
//  GameLayer.cpp
//  GearsOfKMU
//
//  Created by admin on 11/16/15.
//
//

#include "GameLayer.h"

GameLayer::GameLayer()
{
}

GameLayer::~GameLayer()
{
}

Scene* GameLayer::scene()
{
    auto scene = Scene::create();

    auto layer = GameLayer::create();

    scene->addChild(layer);

    return scene;
}

bool GameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
 
    // KMU Logo
    logo = Sprite::create("logo.png");
    logo->setPosition(Vec2(origin.x + logo->getContentSize().width + 50, origin.y + visibleSize.height - 50));
    this->addChild(logo, 1);
    
    // Upgrade button
    auto upgrade = MenuItemImage::create( "UpgradeButtonNormal.png", "UpgradeButtonSelected", CC_CALLBACK_1(GameLayer::UpgradeMenu, this));
    upgrade->setPosition(Vec2(origin.x + upgrade->getContentSize().width + 50, origin.y + visibleSize.height * 0.5));
    auto Upgrade = Menu::create(upgrade, NULL);
    Upgrade->setPosition(Vec2::ZERO);
    this->addChild(Upgrade, 1);
    
    //Statistic buttom
    auto stat = MenuItemImage::create( "StatisticButtonNormal.png", "StatisticButtonSelected", CC_CALLBACK_1(GameLayer::StatisticMenu, this));
    stat->setPosition(Vec2(origin.x + stat->getContentSize().width + 50, origin.y + visibleSize.height * 0.4));
    auto Stat = Menu::create(stat, NULL);
    Stat->setPosition(Vec2::ZERO);
    this->addChild(Stat, 1);

    //ResetButton
    auto reset = MenuItemImage::create( "ResetButtonNormal.png", "ResetButtonSelected", CC_CALLBACK_1(GameLayer::ResetMenu, this));
    reset->setPosition(Vec2(origin.x + stat->getContentSize().width + 50, origin.y + visibleSize.height * 0.4));
    auto Reset = Menu::create(reset, NULL);
    Reset->setPosition(Vec2::ZERO);
    this->addChild(Reset, 1);
    return true;
}


bool GameLayer::onTouchBegan(Touch *touch, Event *event)
{
    return true;
}

void GameLayer::update(float dt)
{
    
}

void GameLayer::UpgradeMenu(Ref *pSender)
{
    
}

void GameLayer::StatisticMenu(Ref *pSender)
{

}