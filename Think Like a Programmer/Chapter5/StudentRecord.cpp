#include <iostream>
#include <string>
#include "StudentRecord.h"
using std::cout;
using std::cin;
using std::string;

StudentRecord::StudentRecord()
{
    setName("");
    setGrade(0);
    setStudentID(-1);
}

StudentRecord::StudentRecord(string newName, int newGrade, int newID)
{
    setName(newName);
    setGrade(newGrade);
    setStudentID(newID);
}

StudentRecord::~StudentRecord()
{
}

void StudentRecord::setName(string newName)
{
    this->name = newName;
}

string StudentRecord::getName()
{
    return this->name;
}

void StudentRecord::setGrade(int newGrade)
{
    if (isValidGrade(newGrade))
        this->grade = newGrade;
}

int StudentRecord::getGrade()
{
    return this->grade;
}

void StudentRecord::setStudentID(int newID)
{
    this->studentID = newID;
}

int StudentRecord::getStudentID()
{
    return this->studentID;
}

string StudentRecord::letterGrade()
{
    if (!isValidGrade(this->grade))
        return "ERROR";

    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = { "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A" };
    const int LOWEST_GRADE_SCORE[] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };
    int category = 0;
    
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= this->grade)
        category++;

    return GRADE_LETTER[category - 1];
}

bool StudentRecord::isValidGrade(int grade)
{
    return ((grade >= 0) && (grade <= 100));
}