
#include <string>
#include <list>

#include "Student.h"
#include "cocos2d.h"
#include "Major.h"

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
	
	bool AddStudent(Student *);
	static Major* setSprite(std::string , int);
    cocos2d::Label* setLabelName(std::string);
    cocos2d::Label* setLabelStudent(std::string);
    cocos2d::Sprite* setAddSprite(std::string);
    
    Major(std::string, int);
	~Major();
};