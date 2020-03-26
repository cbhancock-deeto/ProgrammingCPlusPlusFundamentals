#pragma once
#include "student.h"
#include "degree.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "stdio.h"

class Roster
{
public:
	Roster();
	~Roster();

	void add(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, Degree degreeHeld);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

private:
	int currentSpot;
	const static int arraySize = 5;
	Student *classRosterArray[arraySize];
};

