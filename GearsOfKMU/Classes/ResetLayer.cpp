//
//  ResetLayer.cpp
//  GearsOfKMU
//
//  Created by admin on 12/3/15.
//
//

#include "ResetLayer.h"

ResetLayer::ResetLayer()
{
}

ResetLayer::~ResetLayer()
{
    CC_SAFE_RELEASE(In);
    CC_SAFE_RELEASE(Out);
}

ResetLayer* ResetLayer::create()
{
    auto layer = new ResetLayer();
    return layer;
}

bool ResetLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    txt = cocos2d::Label::createWithTTF("Are you sure you want to reset ?", "fonts/arial.ttf", 20.0f);
    txt->setPosition(cocos2d::Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.7f));
    this->addChild(txt);
    
    //Yes = cocos2d::MenuItemImage::create("", "", CC_CALLBACK_1(ResetLayer::YesFunction, this));
    //                                     No = cocos2d::MenuItemImage::create("", "", CC_CALLBACK_1(ResetLayer::NoFunction, this));
    return true;
}