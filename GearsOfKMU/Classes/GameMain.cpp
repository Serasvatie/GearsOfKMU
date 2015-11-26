#include "GameMain.h"

USING_NS_CC;

GameMain::GameMain()
{ 
}

GameMain::~GameMain()
{ }

Scene* GameMain::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameMain::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameMain::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*
    ** Initialize Ressources
    */
    StudentBySec = 0.1;
    Money = 10;
    MoneyBySecond = 1.5;
    Knowledge = 0;
    for (int i = 0 ; i < 10 ; i++)
    {
        Student* stu = new Student(60.0f);
        Students.push_back(stu);
    }

    /*
    ** Create UI
    */
    // Background
    background = Sprite::create("MainGate.png");
    background->setScale(background->getScale() * 2.f);
    background->setPosition(Vec2(origin.x + background->getContentSize().width / 2, origin.y + background->getContentSize().height / 2));
    this->addChild(background);
    
    // KMU Logo
    logo = Sprite::create("logo.png");
    logo->setPosition(Vec2(origin.x + logo->getContentSize().width - 30, origin.y + visibleSize.height - 50));
    this->addChild(logo);
    
    // Upgrade button
    auto upgrade = MenuItemImage::create( "Button Upgrade Normal.png", "Button Upgrade Selected.png", CC_CALLBACK_1(GameMain::UpgradeMenu, this));
    upgrade->setPosition(Vec2(origin.x + upgrade->getContentSize().width + 15, origin.y + visibleSize.height * 0.5));
    upgrade->setScale(upgrade->getScale() * 2.0f);
    auto Upgrade = Menu::create(upgrade, NULL);
    Upgrade->setPosition(Vec2::ZERO);
    this->addChild(Upgrade, 0);
    
    //Statistic buttom
    auto stat = MenuItemImage::create( "Button StatisticNormal.png", "Button Statistic Selected.png", CC_CALLBACK_1(GameMain::StatisticMenu, this));
    stat->setPosition(Vec2(origin.x + stat->getContentSize().width + 15, origin.y + visibleSize.height * 0.35));
    stat->setScale(stat->getScale() * 2.0f);
    auto Stat = Menu::create(stat, NULL);
    Stat->setPosition(Vec2::ZERO);
    this->addChild(Stat, 0);

    //ResetButton
    auto reset = MenuItemImage::create( "Button Reset Normal.png", "Button Reset Selected.png", CC_CALLBACK_1(GameMain::ResetMenu, this));
    reset->setPosition(Vec2(origin.x + reset->getContentSize().width + 15, origin.y + visibleSize.height * 0.2));
    reset->setScale(reset->getScale() * 2.0f);
    auto Reset = Menu::create(reset, NULL);
    Reset->setPosition(Vec2::ZERO);
    this->addChild(Reset, 0);

    //UI Student
    NBStudent = UI::setSpriteWithFile("StudentZone.png");
    NBStudent->setPosition(Vec2(origin.x + visibleSize.width * 0.30, visibleSize.height - 15));
    NBStudent->setLabelFirst("0", "fonts/arial.ttf", 17.0f);
    NBStudent->setLabelSecond("0", "fonts/arial.ttf", 12.0f);
    this->addChild(NBStudent,0);
    //UI Money
    NBMoney = UI::setSpriteWithFile("MoneyZone.png");
    NBMoney->setPosition(Vec2(origin.x + visibleSize.width * 0.55, visibleSize.height - 15));
    NBMoney->setLabelFirst("0", "fonts/arial.ttf", 17.0f);
    NBMoney->setLabelSecond("0", "fonts/arial.ttf", 12.0f);
    this->addChild(NBMoney,0);
    //UI Knowledge
    NBKnowledge = UI::setSpriteWithFile("KnowledgeZone.png");
    NBKnowledge->setPosition(Vec2(origin.x + visibleSize.width * 0.80, visibleSize.height - 15));
    NBKnowledge->setLabelFirst("0", "fonts/arial.ttf", 17.0f);
    this->addChild(NBKnowledge,0);
    
    //College of Engineering
    Engineering = College::setSpriteWithFile("CollegeZone.png");
    Engineering->setNameOfCollege("College of Engineering");
    Engineering->setMajor("Game & Mobile Dev.", 10, "Dpt. of Electronic Engineering", 5);
    Engineering->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
    this->addChild(Engineering);
    
    this->scheduleUpdate();
    
    return true;
}

bool GameMain::onTouchBegan(Touch *touch, Event *event)
{
    return true;
}

void GameMain::updateRessources()
{
    /*
    ** Update money
    */
    MoneyTmp += MoneyBySecond;
    Money += (int)MoneyTmp;
    MoneyTmp -= (int)MoneyTmp;
    
    /*
    ** Update student
    */
    StudentTmp += StudentBySec;
    while (StudentTmp >= 1.f)
    {
        Student* stu = new Student(60.0f);
        Students.push_back(stu);
        StudentTmp -= 1;
    }
}

void GameMain::updateAffRessources()
{
    NBStudent->updateLabel((int)Students.size(), (float)StudentBySec);
    NBMoney->updateLabel((int)Money, (float)MoneyBySecond);
    NBKnowledge->updateLabel(Knowledge);
}

void GameMain::update(float dt)
{
    /*
    ** Call updateRessources() each second
    */
    second += dt;
    deltaTime += dt;
    if (second >= 1.f)
    {
       updateRessources();
        second = 0.f;
    }
    updateAffRessources();
}

void GameMain::UpgradeMenu(Ref *pSender)
{
    
}

void GameMain::StatisticMenu(Ref *pSender)
{

}

void GameMain::ResetMenu(Ref *pSender)
{
    
}
