//
//  Student.cpp
//  GearsOfKMU
//
//  Created by admin on 11/20/15.
//
//

#include "Student.h"

Student::Student(float time)
{
    this->TimeToGraduate = time;
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
