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

    int index = 0;

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (studentArray[i].grade > studentArray[index].grade)
            index = i;
    }

    cout << "The student with the highest grade is " << studentArray[index].name <<
            " with a score of " << studentArray[index].grade << "\n";
    
    return 0;
}