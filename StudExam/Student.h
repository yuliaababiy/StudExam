#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

template <typename T>
class Student
{
protected:
	string name;
	string surname;
	T age;
	int group;
public :
	Student<T>(string name, string surname, T age, int group);
	virtual void displayIntoFile(ostream& out);
	virtual void display();
	virtual void saveWithSpaces(ostream& out);
	string getName();
	string getSurname();
	int getAge();
	int getGroup();


};
#endif // !STUDENT_H

