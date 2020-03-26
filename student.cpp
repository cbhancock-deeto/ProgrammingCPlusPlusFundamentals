#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(string sID, string fName, string lName, string eAddress, int years, int c1, int c2, int c3) {
	studentID = sID;
	firstName = fName;
	lastName = lName;
	eMail = eAddress;
	age = years;
	courseDays[0] = c1;
	courseDays[1] = c2;
	courseDays[2] = c3;

	return;
}

Student::~Student() {
	cout << "destructor called" << endl;

	return;
}



void Student::setStudentID(string sID) {
	studentID = sID;
}
void Student::setFirstName(string fName) {
	firstName = fName;
}
void Student::setLastName(string lName) {
	lastName = lName;
}
void Student::setEmail(string eAddress) {
	eMail = eAddress;
}
void Student::setAge(int years) {
	age = years;
}
void Student::setCourseDays(int c1, int c2, int c3) {
	courseDays[0] = c1;
	courseDays[1] = c2;
	courseDays[2] = c3;
}


string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return eMail;
}
int Student::getAge() {
	return age;
}
int* Student::getCourseDays() {
	int* dayArray = new int[3];
	dayArray[0] = courseDays[0];
	dayArray[1] = courseDays[1];
	dayArray[2] = courseDays[2];

	return dayArray;
}


void Student::print() {

	int* days = this->getCourseDays();
	cout << "ID: " << this->getStudentID() << endl;
	cout << "Name: " << this->getLastName() << ", " << this->getFirstName() << endl;
	cout << "Email: " << this->getEmail() << endl;
	cout << "Age: " << this->getAge() << endl;
	cout << "Days: " << days[0] << ", " << days[1] << ", " << days[2] << endl;
	delete days;
	return;
}

Degree Student::getDegreeProgram() {

	return degree;
}