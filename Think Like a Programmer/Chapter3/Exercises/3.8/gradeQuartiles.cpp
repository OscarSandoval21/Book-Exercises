/*
    3-8. Write a program that processes an array of student objects and determines
    the grade quartiles—that is, the grade one would need to score as well as or
    better than 25% of the students, 50% of the students, and 75% of the students.
*/

/*
    Plan Outline:
    > The formula for finding out quartiles is (N + 1) * (1/4)
        - With (1/4) for first quartile, (2/4) for second, and (3/4) for third.
    > If the resulting number of a division ends with .5, then the quartile
    is determined by the average of the values in-between the result.
        - If it ends with .75, it must be rounded up. If it ends with .25,
        it must be rounded down.
    > If a number is even, when divided by 2, the result is odd.
        - The result can then be treated as an odd number when divided by 2 itself.
    > If a number is odd, when divided by 2, the results will contain .25 and .75.
        - Here, and only here, I will need to round down and up.
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

void printStudentStruct(student studentArray[], const int ARRAY_SIZE)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].grade << " ";
        cout << studentArray[i].studentID << " ";
        cout << studentArray[i].name << "\n";
    }
}

float getQuartile(float numberOfItems)
{
    return numberOfItems / 2.0f;
}

int findMedianEven(student studentArray[], const int ARRAY_SIZE)
{
    int median = ARRAY_SIZE / 2;

    return (studentArray[median].grade + studentArray[median - 1].grade) / 2;
}

int main() {
    const int ARRAY_SIZE = 12;
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
        {68, 10010, "Veronica"},
        {50, 10011, "Dan"},
        {95, 10012, "Danny"}
    };
    float firstQuartile;
    float secondQuartile;
    float thirdQuartile;
    int lowMiddle;
    int middle;
    int highMiddle;

    cout << "Before sorting:\n";
    printStudentStruct(studentArray, ARRAY_SIZE);

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrades);

    cout << "After sorting grades:\n";
    printStudentStruct(studentArray, ARRAY_SIZE);

    if (ARRAY_SIZE % 2 == 0)
    {
        middle = ARRAY_SIZE / 2;
        lowMiddle = (ARRAY_SIZE / 4);
        secondQuartile = (studentArray[middle].grade + studentArray[middle - 1].grade) / 2.0;
        if (middle % 2 == 0)
        {
            highMiddle = lowMiddle * 3;
            firstQuartile = (studentArray[lowMiddle].grade + studentArray[lowMiddle - 1].grade) / 2.0;
            thirdQuartile = (studentArray[highMiddle].grade + studentArray[highMiddle - 1].grade) / 2.0;
        }
        else
        {
            highMiddle = middle + lowMiddle;
            firstQuartile = studentArray[lowMiddle].grade;
            thirdQuartile = studentArray[highMiddle].grade;
        }

    }
    else
    {
        middle = ARRAY_SIZE / 2;
        lowMiddle = (ARRAY_SIZE / 4);
        secondQuartile = studentArray[middle].grade;
        if (middle % 2 == 0)
        {
            highMiddle = lowMiddle * 3;
            firstQuartile = (studentArray[lowMiddle].grade + studentArray[lowMiddle - 1].grade) / 2.0;
            thirdQuartile = (studentArray[highMiddle].grade + studentArray[highMiddle + 1].grade) / 2.0;
        }
        else
        {
            highMiddle = ((lowMiddle + 1) * 3) - 1;
            firstQuartile = studentArray[lowMiddle].grade;
            thirdQuartile = studentArray[highMiddle].grade;
        }
    }


    cout << "First quartile: " << firstQuartile << "\n";
    cout << "Second quartile: " << secondQuartile << "\n";
    cout << "Third quartile: " << thirdQuartile << "\n";


    return 0;
}