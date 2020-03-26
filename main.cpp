
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <process.h>
#include "degree.h"
#include "student.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "NetworkStudent.h"
#include "Roster.h"

using namespace std;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Cody,Hancock,chanc34@wgu.edu,25,10,15,20,SOFTWARE" };


void main() {

	cout << "Course title: C867" << endl;
	cout << "Language used: C++" << endl;
	cout << "Student ID: #001087330" << endl;
	cout << "Name: Cody Hancock" << endl << endl;

	Roster classRoster;

	// Parsing the student data array
	for (int i = 0; i < 5; i++) {

		vector<string> tokens;

		stringstream inVal(studentData[i]);
		string placeholder;
		while (getline(inVal, placeholder, ',')) {
			tokens.push_back(placeholder);
		}
		Degree deg = SOFTWARE;
		if (tokens[8] == "SOFTWARE") {
			deg = SOFTWARE;
		}
		else if (tokens[8] == "NETWORK") {
			deg = NETWORKING;
		}
		else if (tokens[8] == "SECURITY") {
			deg = SECURITY;
		}

		classRoster.add(tokens[0], tokens[1], tokens[2], tokens[3], stoi(tokens[4]), stoi(tokens[5]), stoi(tokens[6]), stoi(tokens[7]), deg);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printDaysInCourse("A1");
	classRoster.printDaysInCourse("A2");
	classRoster.printDaysInCourse("A3");
	classRoster.printDaysInCourse("A4");
	classRoster.printDaysInCourse("A5");

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	classRoster.remove("A3");

	Roster *destructorRosterExample = new Roster;
	delete destructorRosterExample;
	system("pause");

}
