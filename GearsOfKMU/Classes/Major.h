#ifndef __MAJOR_H__
#define __MAJOR_H__

#include <string>
#include <list>

#include "Student.h"
#include "cocos2d.h"

class Major : public cocos2d::Sprite
{
	private:
	
	public:
	
	bool unlock;
	int MoneyToUnlock;
	int KnowledgeToUnlock;
	
	int NbMaxStudent;
	std::list<Student*> student;
	
	std::string name;
	
	cocos2d::Label* studentLabel;
	
	void AddStudent(Ref *pSender);
    static Major* setSprite(std::string, int);
    cocos2d::Label* setLabelName(std::string);
    cocos2d::Label* setLabelStudent(std::string);
    cocos2d::Menu* setAddSprite(std::string);
    
    Major(std::string, int);
	~Major();
};

#endif // __MAJOR_H__

