/*
    PROBLEM: CLASS ROSTER

    Design a class or set of classes for use in a program that maintains a class roster. For
    each student, store the student’s name, ID, and final grade score in the range 0–100.
    The program will allow student records to be added or removed; display the record of
    a particular student, identified by ID, with the grade displayed as a number and as a
    letter; and display the average score for the class. The appropriate letter grade for a
    particular score is shown in Table 5-1.
*/

/*
    Plan Outline:
    
    > I think a class for a Student would work well here. That way each student can have all of their
    information encapsulated in one object.
    > In order to make a class roster, there would need to be a data structure to store all of the
    student objects. Either an array or a linked list could work, but the problem requires us to
    have the ability to add or remove records, which is what a linked list does best by expanding
    or shrinking as needed.
    > There's no requirement to have the student records sorted in any way, so a linked list would be
    able to provide the best efficiency with its properties.
*/

#include <iostream>
#include <string>

#include "studentRecord.h"

using std::cout;
using std::cin;
using std::string;

int main() {
    
    return 0;
}