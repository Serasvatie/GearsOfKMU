
#include <string>
#include <list>

#include "Student.h"
#include "cocos2d.h"

class Major : public cocos2d::Sprite
{
	private:	
	
	public:
	
	int NbMaxStudent;
	std::list<Student*> student;
	
	std::string name;
	
	bool AddStudent();
	
	static Major* setSpriteWithFile(const char* file);
	
	Major();
	~Major();
};