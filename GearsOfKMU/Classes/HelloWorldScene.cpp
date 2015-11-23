#include "HelloWorldScene.h"

USING_NS_CC;

HelloWorld::HelloWorld() :
    NumberOfStudent(1000), StudentBySec(0.1), Money(1), MoneyBySecond(0),
    Knowledge(0)
{ 
    for (int i = 0 ; i < 10 ; i++)
    {
        Student* stu = new Student(60.0f);
        NumberOfStudent.push_back(stu);
    } 
}

HelloWorld::~HelloWorld()
{ }

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // KMU Logo
    logo = Sprite::create("logo.png");
    logo->setPosition(200, 200);
    logo->setPosition(Vec2(origin.x + logo->getContentSize().width - 30, origin.y + visibleSize.height - 50));
    this->addChild(logo);
/*
    //ResetButton
    auto reset = MenuItemImage::create( "Button Reset Normal.png", "Button Reset Selected.png", CC_CALLBACK_1(HelloWorld::ResetMenu, this));
    reset->setPosition(Vec2(origin.x + reset->getContentSize().width + 50, origin.y + visibleSize.height * 0.4));
    auto Reset = Menu::create(reset, NULL);
    Reset->setPosition(Vec2::ZERO);
    this->addChild(Reset, 0);
*/
    return true;
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
    return true;
}

void HelloWorld::update(float dt)
{
    
}

void HelloWorld::UpgradeMenu(Ref *pSender)
{
    
}

void HelloWorld::StatisticMenu(Ref *pSender)
{

}

void HelloWorld::ResetMenu(Ref *pSender)
{
    
}
