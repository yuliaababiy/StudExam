#include "Student.h"

template <typename T>
Student<T> ::Student<T>(string name, string surname, T age, int group) 
	: name(name), surname(surname), age(age), group(group){}

template <typename T>
void Student<T> ::displayIntoFile(ostream& out)
{
	out << "Name: " << name << " Surname: " << surname << " Age: " << age << " Group: " << group << endl;
}

template <typename T>
void Student<T> ::display()
{
	cout << "Name: " << name << " Surname: " << surname << " Age: " << age << " Group: " << group << endl;
}

template <typename T>
void Student<T> :: saveWithSpaces(ostream& out)
{
	out << "Student " << name << " " << surname << " " << age << " " << group << endl;
}

template <typename T>
string Student<T> ::getName()
{
	return name;
}

template <typename T>
string Student<T> ::getSurname()
{
	return surname;
}

template <typename T>
int Student<T> ::getAge()
{
	return age;
}

template <typename T>
int Student<T> ::getGroup()
{
	return group;
}

template class Student<int>;
template class Student<double>;