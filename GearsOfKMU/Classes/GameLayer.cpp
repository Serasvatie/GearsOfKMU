//
//  GameLayer.cpp
//  GearsOfKMU
//
//  Created by admin on 11/16/15.
//
//

#include <iostream>
#include "GameLayer.h"

GameLayer::GameLayer() : NumberOfStudent(1000)
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
    CCLOG("coucou");
    if ( !Layer::init() )
    {
        return false;
    }
    
    CCLOG("coucou");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
 
    // KMU Logo
    logo = Sprite::create("HelloWorld.png");
    logo->setPosition(200, 200);
    //logo->setPosition(Vec2(origin.x + logo->getContentSize().width + 50, origin.y + visibleSize.height - 50));
    this->addChild(logo);
    /*
    // Upgrade button
    auto upgrade = MenuItemImage::create( "Button Upgrade Normal.png", "Button Upgrade Selected.png", CC_CALLBACK_1(GameLayer::UpgradeMenu, this));
    upgrade->setPosition(Vec2(origin.x + upgrade->getContentSize().width + 50, origin.y + visibleSize.height * 0.5));
    auto Upgrade = Menu::create(upgrade, NULL);
    Upgrade->setPosition(Vec2::ZERO);
    this->addChild(Upgrade, 0);
    
    //Statistic buttom
    auto stat = MenuItemImage::create( "Button StatisticNormal.png", "Button Statistic Selected.png", CC_CALLBACK_1(GameLayer::StatisticMenu, this));
    stat->setPosition(Vec2(origin.x + stat->getContentSize().width + 50, origin.y + visibleSize.height * 0.4));
    auto Stat = Menu::create(stat, NULL);
    Stat->setPosition(Vec2::ZERO);
    this->addChild(Stat, 0);

    //ResetButton
    auto reset = MenuItemImage::create( "Button Reset Normal.png", "Button Reset Selected.png", CC_CALLBACK_1(GameLayer::ResetMenu, this));
    reset->setPosition(Vec2(origin.x + stat->getContentSize().width + 50, origin.y + visibleSize.height * 0.4));
    auto Reset = Menu::create(reset, NULL);
    Reset->setPosition(Vec2::ZERO);
    this->addChild(Reset, 0);*/
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

void GameLayer::ResetMenu(Ref *pSender)
{
    
}