//
//  Student.h
//  GearsOfKMU
//
//  Created by admin on 11/20/15.
//
//

#ifndef __GearsOfKMU__Student__
#define __GearsOfKMU__Student__

#include <stdio.h>

class Student
{
public:
    Student();
    ~Student();

    bool updateTime(float dt);
    bool startStudy;
	void setTimeToGraduate(float);
    
private:
    float TimeToGraduate;
};

#endif /* defined(__GearsOfKMU__Student__) */
