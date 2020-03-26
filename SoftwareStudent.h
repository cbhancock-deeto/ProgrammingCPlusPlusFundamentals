#pragma once
#include "student.h"
#include "degree.h"
class SoftwareStudent :
	public Student
{
public:
	SoftwareStudent();
	~SoftwareStudent();
	Degree getDegreeProgram();

private:
	Degree degree;
};

