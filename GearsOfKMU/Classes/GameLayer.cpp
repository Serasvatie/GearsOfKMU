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
    return true;
}


bool GameLayer::onTouchBegan(Touch *touch, Event *event)
{
    return true;
}

void GameLayer::update(float dt)
{
    
}




