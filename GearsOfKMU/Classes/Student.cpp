//
//  Student.cpp
//  GearsOfKMU
//
//  Created by admin on 11/20/15.
//
//

#include "Student.h"
#include "cocos2d.h"

Student::Student()
{
    this->startStudy = false;
}

Student::~Student()
{
}

bool Student::updateTime(float dt)
{
    if (startStudy)
        TimeToGraduate = TimeToGraduate - dt;
    if (TimeToGraduate <= 0)
        return true;
    return false;
}

void Student::setTimeToGraduate(float time)
{
	TimeToGraduate = time;
}
