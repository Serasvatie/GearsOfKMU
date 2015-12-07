#include "GameMain.h"

using namespace CocosDenshion;

USING_NS_CC;

GameMain::GameMain()
{ 
}

GameMain::~GameMain()
{
}

Scene* GameMain::createScene()
{
<<<<<<< Updated upstream
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = GameMain::create();
	layer->ResetLay = ResetLayer::create();
=======
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameMain::create();
    auto layerUpgrade = UpgradeLayer::create();

    // add layer as a child to scene
    scene->addChild(layer, 0);
    scene->addChild(layerUpgrade, 1);
>>>>>>> Stashed changes

	// add layer as a child to scene
	scene->addChild(layer);
	scene->addChild(layer->ResetLay, 2);
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
	StudentBySec = STUDENTBYSEC_START;
	Money = MONEY_START;
	MoneyBySecond = MONEYBYSECOND_START;
	Knowledge = KNOWLEDGE_START;
	second = 0.f;
	MoneyTmp = 0.f;
	StudentTmp = 0.f;
	for (int i = 0 ; i < STUDENT_START; i++)
	{
		Student* stu = new Student();
		Students.push_back(stu);
	}

<<<<<<< Updated upstream
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
=======
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
>>>>>>> Stashed changes

	//ResetButton
	auto reset = MenuItemImage::create("Button Reset Normal.png", "Button Reset Selected.png", CC_CALLBACK_1(GameMain::ResetMenu, this));
	reset->setPosition(Vec2(origin.x + reset->getContentSize().width + 15, origin.y + visibleSize.height * 0.2));
	reset->setScale(reset->getScale() * 2.0f);
	auto Reset = Menu::create(reset, NULL);
	Reset->setPosition(Vec2::ZERO);
	this->addChild(Reset, 0);

	//UI Student
	NBStudent = UI::setSpriteWithFile("StudentZone.png");
	NBStudent->setPosition(Vec2(origin.x + visibleSize.width * 0.30, visibleSize.height - 15));
	NBStudent->setLabelFirst("0", FONT, 20.0f);
	NBStudent->setLabelSecond("0", FONT, 13.0f);
	this->addChild(NBStudent,0);
	//UI Money
	NBMoney = UI::setSpriteWithFile("MoneyZone.png");
	NBMoney->setPosition(Vec2(origin.x + visibleSize.width * 0.55, visibleSize.height - 15));
	NBMoney->setLabelFirst("0", FONT, 20.0f);
	NBMoney->setLabelSecond("0", FONT, 13.0f);
	this->addChild(NBMoney,0);
	//UI Knowledge
	NBKnowledge = UI::setSpriteWithFile("KnowledgeZone.png");
	NBKnowledge->setPosition(Vec2(origin.x + visibleSize.width * 0.80, visibleSize.height - 15));
	NBKnowledge->setLabelFirst("0", FONT, 20.0f);
	this->addChild(NBKnowledge,0);
	
	//College of Engineering
	Engineering = College::setSpriteWithFile("CollegeZone.png");
	Engineering->setScale(Engineering->getScale() * 1.2);
	Engineering->setPosition(Vec2(visibleSize.width * 0.35, visibleSize.height * 0.75));
	Engineering->setNameOfCollege("College of Engineering", 8.0f, ENGINEERING_UNLOCK, ENGINEERING_MONEYUNLOCK, ENGINEERING_KNOWLEDGEUNLOCK);
	Engineering->setMajor("Game and Mobile Dev.", ENGINEERING_MAJOR1_MAXSTUDENT, 11.0f, ENGINEERING_MAJOR1_TIMETOGRADUATE,
						  "Dpt. of Electronic Engineering", ENGINEERING_MAJOR2_MAXSTUDENT, 9.0f, ENGINEERING_MAJOR2_TIMETOGRADUATE);
	this->addChild(Engineering);
	
	//College of Medecine
	Medecine = College::setSpriteWithFile("CollegeZone.png");
	Medecine->setScale(Medecine->getScale() * 1.2);
	Medecine->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.75));
	Medecine->setNameOfCollege("College of Medecine", 8.0f, MEDECINE_UNLOCK, MEDECINE_MONEYUNCLOCK, MEDECINE_KNOWLEDGEUNLOCK);
	Medecine->setMajor("Medecine Department", MEDECINE_MAJOR1_MAXSTUDENT, 12.0f, MEDECINE_MAJOR1_TIMETOGRADUATE,
					   "Biomedical Engineering", MEDECINE_MAJOR2_MAXSTUDENT, 11.0f, MEDECINE_MAJOR2_TIMETOGRADUATE);
	this->addChild(Medecine);
	
	//College of Education
	Education = College::setSpriteWithFile("CollegeZone.png");
	Education->setScale(Education->getScale() * 1.2);
	Education->setPosition(Vec2(visibleSize.width * 0.35, visibleSize.height * 0.53));
	Education->setNameOfCollege("College of Education", 8.0f, EDUCATION_UNLOCK, EDUCATION_MONEYUNCLOCK, EDUCATION_KNOWLEDGEUNLOCK);
	Education->setMajor("Korean Language Education", EDUCATION_MAJOR1_MAXSTUDENT, 9.0f, EDUCATION_MAJOR1_TIMETOGRADUATE,
						"Early Childhoud Education", EDUCATION_MAJOR2_MAXSTUDENT, 10.0f, EDUCATION_MAJOR2_TIMETOGRADUATE);
	this->addChild(Education);
	
	//College of Social
	Social = College::setSpriteWithFile("CollegeZone.png");
	Social->setScale(Social->getScale() * 1.2);
	Social->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.53));
	Social->setNameOfCollege("College of Social Science", 8.0f, SOCIAL_UNLOCK, SOCIAL_MONEYUNCLOCK, SOCIAL_KNOWLEDGEUNLOCK);
	Social->setMajor("Dpt. of Int. Trade and Commerce", SOCIAL_MAJOR1_MAXSTUDENT, 8.0f, SOCIAL_MAJOR1_TIMETOGRADUATE,
					 "Dpt. of Public Administration", SOCIAL_MAJOR2_MAXSTUDENT, 9.0f, SOCIAL_MAJOR2_TIMETOGRADUATE);
	this->addChild(Social);
	
	//College of Natural
	Natural = College::setSpriteWithFile("CollegeZone.png");
	Natural->setScale(Natural->getScale() * 1.2);
	Natural->setPosition(Vec2(visibleSize.width * 0.35, visibleSize.height * 0.31));
	Natural->setNameOfCollege("College of Natural Science", 8.0f, NATURAL_UNLOCK, NATURAL_MONEYUNCLOCK, NATURAL_KNOWLEDGEUNLOCK);
	Natural->setMajor("Mathematics Department", NATURAL_MAJOR1_MAXSTUDENT, 10.0f, NATURAL_MAJOR1_TIMETOGRADUATE,
					  "Global Environnement Dpt.", NATURAL_MAJOR2_MAXSTUDENT, 10.0f, NATURAL_MAJOR2_TIMETOGRADUATE);
	this->addChild(Natural);
	
	// College of Music
	Music = College::setSpriteWithFile("CollegeZone.png");
	Music->setScale(Music->getScale() * 1.2);
	Music->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.31));
	Music->setNameOfCollege("College of Music and Perfoming Arts", 7.0f, MUSIC_UNLOCK, MUSIC_MONEYUNCLOCK, MUSIC_KNOWLEDGEUNLOCK);
	Music->setMajor("Orchestral Instruments Dpt.", MUSIC_MAJOR1_MAXSTUDENT, 9.0f, MUSIC_MAJOR1_TIMETOGRADUATE,
					"Dance Department", MUSIC_MAJOR2_MAXSTUDENT, 12.0f, MUSIC_MAJOR2_TIMETOGRADUATE);
	this->addChild(Music);

	// Play music
	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("Background.mp3", true);
	audio->setBackgroundMusicVolume(BACKGROUND_MUSIC_VOLUME);
	
	this->scheduleUpdate();
	
	return true;
}

bool GameMain::onTouchBegan(Touch *touch, Event *event)
{
	return true;
}

int GameMain::getNbStudentInEachCollege()
{
	int ret;
	
	ret = Medecine->getNumberOfStudents();
	ret += Engineering->getNumberOfStudents();
	ret += Education->getNumberOfStudents();
	ret += Social->getNumberOfStudents();
	ret += Natural->getNumberOfStudents();
	ret += Music->getNumberOfStudents();
	
	return ret;
}

void GameMain::updateRessources()
{
	/*
	** Update money
	*/
	MoneyBySecond = (getNbStudentInEachCollege() * MONEY_FOR_EACH_STUDENT) + MONEYBYSECOND_START;
	MoneyTmp += MoneyBySecond;
	Money += (int)MoneyTmp;
	MoneyTmp -= (int)MoneyTmp;
	
	/*
	** Update student
	*/
	StudentTmp += StudentBySec;
	while (StudentTmp >= 1.f)
	{
		Student* stu = new Student();
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

void GameMain::updateCollege(float dt)
{
	Medecine->update(dt);
	Engineering->update(dt);
	Education->update(dt);
	Social->update(dt);
	Natural->update(dt);
	Music->update(dt);
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
	updateCollege(dt);
}

void GameMain::AddKnowledge(int addvalue)
{
	Knowledge += addvalue;
}

void GameMain::UpgradeMenu(Ref *pSender)
{
	auto audio = SimpleAudioEngine::getInstance();
	
	if (Money >= 50)
	{
		audio->playEffect("clickbutton.mp3", false, 1.0f, 1.0f, 1.0f);
		StudentBySec += 0.1f;
		Money -= 50;
	}
	else
	{
		audio->playEffect("invalid.mp3", false, 1.0f, 1.0f, 1.0f);
	}
}

void GameMain::StatisticMenu(Ref *pSender)
{

}

void GameMain::ResetMenu(Ref *pSender)
{
	ResetLay->Show();
}

void GameMain::TrueReset()
{
	StudentBySec = STUDENTBYSEC_START;
	Money = MONEY_START;
	MoneyBySecond = MONEYBYSECOND_START;
	Knowledge = KNOWLEDGE_START;
	second = 0.f;
	MoneyTmp = 0.f;
	StudentTmp = 0.f;
	Students.clear();
	for (int i = 0; i < STUDENT_START; i++)
	{
		Student* stu = new Student();
		Students.push_back(stu);
	}
	Engineering->Reset(ENGINEERING_UNLOCK, ENGINEERING_MONEYUNLOCK, ENGINEERING_KNOWLEDGEUNLOCK,
		ENGINEERING_MAJOR1_MAXSTUDENT, ENGINEERING_MAJOR1_TIMETOGRADUATE,
		ENGINEERING_MAJOR2_MAXSTUDENT, ENGINEERING_MAJOR2_TIMETOGRADUATE);
	Medecine->Reset(MEDECINE_UNLOCK, MEDECINE_MONEYUNCLOCK, MEDECINE_KNOWLEDGEUNLOCK,
		MEDECINE_MAJOR1_MAXSTUDENT, MEDECINE_MAJOR1_TIMETOGRADUATE,
		MEDECINE_MAJOR2_MAXSTUDENT, MEDECINE_MAJOR2_TIMETOGRADUATE);
	Education->Reset(EDUCATION_UNLOCK, EDUCATION_MONEYUNCLOCK, EDUCATION_KNOWLEDGEUNLOCK,
		EDUCATION_MAJOR1_MAXSTUDENT, EDUCATION_MAJOR1_TIMETOGRADUATE,
		EDUCATION_MAJOR2_MAXSTUDENT, EDUCATION_MAJOR2_TIMETOGRADUATE);
	Social->Reset(SOCIAL_UNLOCK, SOCIAL_MONEYUNCLOCK, SOCIAL_KNOWLEDGEUNLOCK,
		SOCIAL_MAJOR1_MAXSTUDENT, SOCIAL_MAJOR1_TIMETOGRADUATE,
		SOCIAL_MAJOR2_MAXSTUDENT, SOCIAL_MAJOR2_TIMETOGRADUATE);
	Natural->Reset(NATURAL_UNLOCK, NATURAL_MONEYUNCLOCK, NATURAL_KNOWLEDGEUNLOCK,
		NATURAL_MAJOR1_MAXSTUDENT, NATURAL_MAJOR1_TIMETOGRADUATE,
		NATURAL_MAJOR2_MAXSTUDENT, NATURAL_MAJOR2_TIMETOGRADUATE);
	Music->Reset(MUSIC_UNLOCK, MUSIC_MONEYUNCLOCK, MUSIC_KNOWLEDGEUNLOCK,
		MUSIC_MAJOR1_MAXSTUDENT, MUSIC_MAJOR1_TIMETOGRADUATE,
		MUSIC_MAJOR2_MAXSTUDENT, MUSIC_MAJOR2_TIMETOGRADUATE);
}

