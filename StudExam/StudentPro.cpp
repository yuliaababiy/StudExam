#include "StudentPro.h"

template<typename T>
StudentPro<T> ::StudentPro<T>(string name, string surname, T age, int group, string subject, double averageScore)
	: Student<T>(name, surname, age, group), subject(subject), averageScore(averageScore) {}

template <typename T>
void StudentPro<T> :: displayIntoFile(ostream& out)
{
	out << "Name: " << this->name << " Surname: " << this->surname << " Age: " << this->age << " Group: " << this->group <<
		" Subject: " << subject << " AverageScore:" << averageScore << endl;
}

template <typename T>
void StudentPro<T> ::display()
{
	cout << "Name: " << this->name << " Surname: " << this->surname << " Age: " << this->age << " Group: " << this->group <<
		" Subject: " << subject << " AverageScore:" << averageScore << endl;
}

template <typename T>
void StudentPro<T> ::saveWithSpaces(ostream& out)
{
	out << "StudentPro " << this->name << " " << this->surname << " " << this->age << " " << this->group <<
		" " << subject <<  " " << averageScore << endl;
}

template <typename T>
double StudentPro<T> ::getAverageScore()
{
	return averageScore;
}

template class StudentPro<int>;
template class StudentPro<double>;