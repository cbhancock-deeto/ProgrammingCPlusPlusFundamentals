#pragma once
#include "student.h"
#include "degree.h"
#include <string>
class SecurityStudent :
	public Student
{
public:
	SecurityStudent();
	~SecurityStudent();
	Degree getDegreeProgram();

private:
	Degree degree;
};

