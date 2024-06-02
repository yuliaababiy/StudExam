#ifndef STUDENTPRO_H
#define STUDENTPRO_H
#include "Student.h"
#include <iostream>
using namespace std;

template <typename T>
class StudentPro : public Student<T>
{
protected:
	string subject;
	double averageScore;
public:
	StudentPro(string name, string surname, T age, int group, string subject, double averageScore);
	void displayIntoFile(ostream& out) override;
	void display() override;
	void saveWithSpaces(ostream& out) override;
	double getAverageScore();
};

#endif // !STUDENTPRO

