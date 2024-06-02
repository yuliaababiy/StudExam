#include "Student.h"
#include "StudentPro.h"
#include<vector>
#include<set>
#include<fstream>
#include<iostream>
#include <algorithm>
using namespace std;

template <typename T>
void displayStudent(vector<Student<T>*>& students)
{
	for (auto student : students)
	{
		student->display();
	}
	students.clear();
}

template <typename T>
void saveToFile(vector<Student<T>*>& students, string filename)
{
	ofstream file(filename);
	for (auto s : students)
	{
		s->displayIntoFile(file);
	}
	students.clear();
}

template <typename T>
void loadFromFile(vector<Student<T>*>& students, string filename)
{
	ifstream file(filename);
	string name, surname, subject;
	int age, group;
	double averageScore;
	string type;
	while (file >> type >> name >> surname >> age >> group)
	{
		if (type == "Student")
		{
			students.push_back(new Student<T>(name, surname, age, group));
		}
		else if (type == "StudentPro")
		{
			file >> subject >> averageScore;
			students.push_back(new StudentPro<T>(name, surname, age, group, subject, averageScore));
		}
	}
}
int main()
{
	vector<Student<int>*>students;
	ofstream file("input.txt", ios::app);
	int choice;
	while (true)
	{
		cout << "Enter action: " << endl;
		cout << "1-load from file and print: " << endl;
		cout << "2-add oject to file: " << endl;
		cout << "3-print object into file: " << endl;
		cout << "4-find the youngest student: " << endl;
		cout << "5-find the oldest student: " << endl;
		cout << "6-find average age of all students: " << endl;
		cout << "7-exit: " << endl;
		cin >> choice;
		if (choice == 1)
		{
			loadFromFile(students, "input.txt");
			displayStudent(students);
		}
		else if (choice == 2)
		{
			string name, surname, subject;
			int age, group;
			string type;
			double averageScore;
			cout << "Enter type students: ";
			cin >> type;
			if (type == "Student")
			{
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter surname: ";
				cin >> surname;
				cout << "Enter age: ";
				cin >> age;
				cout << "Enter group: ";
				cin >> group;
				Student<int>* s = new Student<int>(name, surname, age, group);
				s->saveWithSpaces(file);
			}
			else if (type == "StudentPro")
			{
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter surname: ";
				cin >> surname;
				cout << "Enter age: ";
				cin >> age;
				cout << "Enter group: ";
				cin >> group;
				cout << "Enter subject: ";
				cin >> subject;
				cout << "Enter averageScore: ";
				cin >> averageScore;
				StudentPro<int>* p = new StudentPro<int>(name, surname, age, group, subject, averageScore);
				p->saveWithSpaces(file);
			}
			else
			{
				cout << "Error!" << endl;
				break;
			}

		}
		else if (choice == 3)
		{
			loadFromFile(students, "input.txt");
			saveToFile(students, "output.txt");
		}
		else if (choice == 4) //find the youngest student
		{
			loadFromFile(students, "input.txt");
			// Student<int>* youngest = new Student<int>("", "", 100, 0);
			Student<int>* youngest = students[0];
			for (auto s : students)
			{
				if (s->getAge() < youngest->getAge()) {
					youngest = s;
				}
			}
			cout << "The youngest student: ";
			youngest->display();
			cout << endl;
		}
		else if (choice == 5) //find the oldest student
		{
			loadFromFile(students, "input.txt");
			// Student<int>* oldest = new Student<int>("", "", 0, 0);
			Student<int>* oldest = students[0];
			for (auto s : students)
			{
				if (s->getAge() > oldest->getAge())
				{
					oldest = s;
				}
			}
			cout << "The oldest student: ";
			oldest->display();
			cout << endl;
		}
		else if (choice == 6) //find average age of students??
		{
			loadFromFile(students, "input.txt");
			int totalAge = 0;
			double averageAge = 0;
			for (auto s : students)
			{
				totalAge += s->getAge();
			}
			averageAge = totalAge / students.size();
			cout << "Average age all students: "<< averageAge;
			cout << endl;
		}
		else if (choice == 7)
		{
			break;
		}
	}
}
