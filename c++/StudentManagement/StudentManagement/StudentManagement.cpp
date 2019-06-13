// StudentManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#define size 100
using namespace std;

struct Student
{
	int id;
	string name;
	float score;
};

Student *student_arr = new Student[size];
int csize = 0;


Student Input();								 
bool CheckID(int id);							 
void Choose();							         
void Menu();									 
void LoadFile(string FileName);			 
void SaveToFile(string FileName);				 
void Display();								 
void Replace(string &str, char to, char by);     

void main()
{
	Choose();
}

void Menu()
{
	cout << "---------------MENU---------------\n";
	cout << "    1. Input                     \n";
	cout << "    2. Display                   \n";
	cout << "    3. Save to file              \n";
	cout << "    4. Load from file            \n";
	cout << "    0. Exit                      \n";
	cout << "----------------------------------\n";
}

void Choose() {
	int choose;
	while (true)
	{
		Menu();
		cout << "Choose: ";
		cin >> choose;

		fflush(stdin);
		if (choose == 0) {
			break;
		}
		if (choose == 1)
		{
			Student student = Input();
			student_arr[csize] = student;
			csize++;
		}
		else if (choose == 2)
		{
			cout << endl;
			Display();
			cout << endl;
		}
		else if (choose == 3)
		{
			SaveToFile("file.txt");
		}
		else if (choose == 4)
		{
			LoadFile("file.txt");
			Display();
		}
	}
}

bool CheckID(int id)
{
	for (register int i = 0; i < csize; i++)
	{
		if (student_arr[i].id == id)
		{
			cout << "This ID already taken." << endl;
			return true;
		}
	}
	return false;
}

Student Input()
{
	Student student;
	bool check;
	cout << "Input student information: " << endl;
	do {
		cout << "Id: ";
		cin >> student.id;
		if (!CheckID(student.id))
		{
			break;
		}
	} while (true);

	cin.ignore();
	cout << "Name: ";
	getline(cin, student.name);

	do
	{
		check = false;
		cout << "Score: ";
		cin >> student.score;
		//Check that score can't reach over 0-10
		if (student.score > 10 || student.score < 0)
		{
			cout << "Score incorrect. ";
			check = true;
		}
	} while (check);

	return student;
}

void Display()
{
	cout << setw(10) << left << "ID" << setw(20) << left << "NAME " << setw(10) << left << "SCORE" << endl;
	for (register int i = 0; i < csize; i++)
	{
		cout << setw(10) << left << student_arr[i].id
			<< setw(20) << left << student_arr[i].name
			<< setw(10) << left << student_arr[i].score;
		cout << endl;
	}
}

void SaveToFile(string fileName)
{
	ofstream f;
	f.open(fileName);
	if (f.is_open())
	{
		f << csize << endl;
		for (register int i = 0; i < csize; i++)
		{
			Student s = student_arr[i];
			register string name = student_arr[i].name;
			Replace(name, ' ', '_');
			f << student_arr[i].id << " " << name << " " << student_arr[i].score << endl;
		}

		cout << "Save to " << fileName << endl;
		f.close();
	}
	else
	{
		cout << "SAVE FILE TO ERROR." << endl;
	}
}

void LoadFile(string FileName)
{
	ifstream f;
	f.open(FileName);
	if (f.is_open())
	{
		int *pointer;
		pointer = &csize;
		f >> *pointer;
		for (int i = 0; i < *pointer; i++)
		{
			Student s;
			register string name;
			f >> s.id;

			f >> name;
			Replace(name, '_', ' ');
			s.name = name;

			f >> s.score;
			student_arr[i] = s;
		}

		f.close();
	}
	else
	{
		cout << "LOAD FILE ERROR." << endl;
	}
}

void Replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
}