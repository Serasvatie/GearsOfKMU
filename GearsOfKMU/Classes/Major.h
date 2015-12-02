#ifndef __MAJOR_H__
#define __MAJOR_H__

#include <string>
#include <list>

#include "Student.h"
#include "cocos2d.h"

class Major : public cocos2d::Node
{
private:
	
	bool unlock;
	int MoneyToUnlock;
	int KnowledgeToUnlock;

	float TimeToGraduate;

	int NbMaxStudent;
	std::list<Student*> student;
	std::string name;
    
	cocos2d::Label* studentLabel;

public:
	
    cocos2d::Menu* Button;
    
	void AddStudent(Ref *pSender);
    static Major* setSprite(std::string, int);
    cocos2d::Label* setLabelName(std::string, float);
    cocos2d::Label* setLabelStudent(std::string, float);
    cocos2d::Menu* setAddSprite();
	void setTimeToGraduate(float time);
	virtual void update(float dt);

    int getNbStudent();
    
    Major(std::string, int);
	~Major();
};

#endif // __MAJOR_H__

