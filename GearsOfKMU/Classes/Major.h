
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
	
	bool AddStudent();
	
	static Major* setSprite(std::string , int);
    cocos2d::Label* setLabelName(std::string, std::string, std::string);
    cocos2d::Label* setLabelStudent(std::string, std::string, std::string);
    cocos2d::Sprite* setAddSprite(std::string);
    
    Major(std::string, int);
	~Major();
};