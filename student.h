
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h" 
#include <string>
using namespace std;


class Student {
public:
	Student(string sID = "N/A", string fName = "N/A", string lName = "N/A",
		string eaddress = "N/A", int years = 18, int c1 = 1, int c2 = 1, int c3 = 1);
	~Student();
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int *getCourseDays();

	void setStudentID(string sID);
	void setFirstName(string fname);
	void setLastName(string lname);
	void setEmail(string eAddress);
	void setAge(int years);
	void setCourseDays(int c1, int c2, int c3);

	virtual void print();
	virtual Degree getDegreeProgram();

protected:
	string studentID;
	string firstName;
	string lastName;
	string eMail;
	int age;
	int courseDays[3];
	Degree degree;

};

#endif 