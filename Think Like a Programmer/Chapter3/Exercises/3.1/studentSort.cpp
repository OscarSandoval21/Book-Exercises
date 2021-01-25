/*
    3-1. Are you disappointed we didn’t do more with sorting? I’m here to help. To
    make sure you are comfortable with qsort, write code that uses the function
    to sort an array of our student struct. First have it sort by grade, and then try
    it again using the student ID.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

struct student {
    int grade;
    int studentID;
    string name;
};

int compareGrades(const void* voidA, const void* voidB)
{
    student* studentA = (student*)(voidA);
    student* studentB = (student*)(voidB);

    // Dereference the pointers so we can access the values stored inside of them,
    // not the address.
    return (studentA->grade - studentB->grade);
}

int compareID(const void* voidA, const void* voidB)
{
    student* studentA = (student*)(voidA);
    student* studentB = (student*)(voidB);

    // Dereference the pointers so we can access the values stored inside of them,
    // not the address.
    return (studentA->studentID - studentB->studentID);
}

void printStudentStruct(student studentArray[], const int ARRAY_SIZE)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].grade << " ";
        cout << studentArray[i].studentID << " ";
        cout << studentArray[i].name << "\n";
    }
}

int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    cout << "Before sorting:\n";
    printStudentStruct(studentArray, ARRAY_SIZE);

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrades);

    cout << "Before sorting grades:\n";
    printStudentStruct(studentArray, ARRAY_SIZE);

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareID);

    cout << "Before sorting IDs:\n";
    printStudentStruct(studentArray, ARRAY_SIZE);
    
    return 0;
}