#include "Roster.h"


Roster::Roster()
{
	currentSpot = 0;
}


Roster::~Roster()
{
	delete classRosterArray;
}

void Roster::add(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, Degree degreeHeld) {

	Student *s1 = new Student;


	switch (degreeHeld) {
	case SECURITY:
		s1 = new SecurityStudent;
		break;
	case NETWORKING:
		s1 = new NetworkStudent;
		break;
	case SOFTWARE:
		s1 = new SoftwareStudent;
		break;
	}

	s1->setStudentID(studentID);
	s1->setFirstName(firstName);
	s1->setLastName(lastName);
	s1->setEmail(emailAddress);
	s1->setAge(age);
	s1->setCourseDays(daysInCourse1, daysInCourse2, daysInCourse3);

	classRosterArray[currentSpot] = s1;

	currentSpot += 1;

}

void Roster::printAll() {

	for (int i = 0; i < currentSpot; i++) {
		string deg;
		Degree degType = classRosterArray[i]->getDegreeProgram();
		switch (degType) {
		case SECURITY:
			deg = "SECURITY";
			break;
		case NETWORKING:
			deg = "NETWORKING";
			break;
		case SOFTWARE:
			deg = "SOFTWARE";
			break;
		}
		int* days = classRosterArray[i]->getCourseDays();
		cout << i + 1 << "\tFirst Name: " << classRosterArray[i]->getFirstName() << "\tLast Name: "
			<< classRosterArray[i]->getLastName() << "\tAge: " << classRosterArray[i]->getAge()
			<< "\tdaysInCourse: (" << days[0] << ", " << days[1] << ", " << days[2] << "), " << "Degree Program: "
			<< deg << endl;

		delete days;
	}

}

void Roster::printDaysInCourse(string studentID) {
	int studentIndex;
	for (int i = 0; i < currentSpot; i++) {

		if (classRosterArray[i]->getStudentID() == studentID) {
			studentIndex = i;
		}
	}

	int* days = classRosterArray[studentIndex]->getCourseDays();
	double totalDays = days[0] + days[1] + days[2];
	double avgDays = totalDays / 3;
	cout << "Average days in three courses: " << avgDays << endl;

}

void Roster::printInvalidEmails() {
	cout << "Invalid emails: " << endl;
	for (int i = 0; i < currentSpot; i++) {
		string email = classRosterArray[i]->getEmail();
		int elength = email.length();


		bool containsSpace = false;
		bool containsDot = false;
		bool containsAt = false;
		for (int j = 0; j < elength; j++) {
			if (email[j] == ' ') {
				containsSpace = true;
			}
			if (email[j] == '@') {
				containsAt = true;
			}
			if (email[j] == '.') {
				containsDot = true;
			}
		}
		if (containsSpace || !containsDot || !containsAt) {
			cout << "Invalid e-mail: Student ID - " << classRosterArray[i]->getStudentID() << endl << "Email Address : "
				<< classRosterArray[i]->getEmail() << endl;
		}

	}
}

void Roster::remove(string studentID) {
	int size = currentSpot;
	Student *newClassRoster[arraySize];
	int index = 0;
	bool found = false;

	for (int i = 0; i < size; i++) {
		if (classRosterArray[i]->getStudentID() != studentID) {
			newClassRoster[index] = classRosterArray[i];
		}
		else {
			found = true;
			currentSpot--;
		}
	}
	if (!found) {
		cout << "Error: student ID does not exist." << endl;
		return;
	}
	memcpy(classRosterArray, newClassRoster, currentSpot);
}

// Receives an integer which must correspond to correct degree type
// 0 - SECURITY
// 1 - NETWORKING
// 2 - SOFTWARE
void Roster::printByDegreeProgram(int degreeProgram) {
	switch (degreeProgram) {
	case 0:
		cout << "Getting SECURITY students: " << endl;
		for (int i = 0; i < currentSpot; i++) {
			if (classRosterArray[i]->getDegreeProgram() == SECURITY) {
				int* days = classRosterArray[i]->getCourseDays();
				cout << "First Name: " << classRosterArray[i]->getFirstName() << "\tLast Name: "
					<< classRosterArray[i]->getLastName() << "\tAge: " << classRosterArray[i]->getAge()
					<< "\tdaysInCourse: (" << days[0] << ", " << days[1] << ", " << days[2] << "), "
					<< "Degree Program: SECURITY" << endl;

				delete days;
			}
		}
		break;
	case 1:
		cout << "Getting NETWORKING students: " << endl;
		for (int i = 0; i < currentSpot; i++) {
			if (classRosterArray[i]->getDegreeProgram() == NETWORKING) {
				int* days = classRosterArray[i]->getCourseDays();
				cout << "First Name: " << classRosterArray[i]->getFirstName() << "\tLast Name: "
					<< classRosterArray[i]->getLastName() << "\tAge: " << classRosterArray[i]->getAge()
					<< "\tdaysInCourse: (" << days[0] << ", " << days[1] << ", " << days[2] << "), "
					<< "Degree Program: NETWORKING" << endl;
				delete days;
			}
		}
		break;
	case 2:
		cout << "getting SOFTWARE students: " << endl;
		for (int i = 0; i < currentSpot; i++)
		{
			if (classRosterArray[i]->getDegreeProgram() == SOFTWARE) {
				int* days = classRosterArray[i]->getCourseDays();
				cout << "First Name: " << classRosterArray[i]->getFirstName() << "\tLast Name: "
					<< classRosterArray[i]->getLastName() << "\tAge: " << classRosterArray[i]->getAge()
					<< "\tdaysInCourse: (" << days[0] << ", " << days[1] << ", " << days[2] << "), "
					<< "Degree Program: SOFTWARE" << endl;


				delete days;
			}
		}
		break;
	}
}