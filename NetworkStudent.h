#pragma once
#include "student.h"
class NetworkStudent :
	public Student
{
public:
	NetworkStudent();
	~NetworkStudent();
	Degree getDegreeProgram();

private:
	Degree degree;
};


