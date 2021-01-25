/*
    PROBLEM: TRACKING AN UNKNOWN QUANTITY OF STUDENT RECORDS

    In this problem, you will write functions to store and manipulate a collection of student
    records. A student record contains a student number and a grade, both integers. The
    following functions are to be implemented:

        addRecord: This function takes a pointer to a collection of student records, a student
        number, and a grade, and it adds a new record with this data to the collection.
        averageRecord: This function takes a pointer to a collection of student records
        and returns the simple average of student grades in the collection as a double.

    The collection can be of any size. The addRecord operation is expected to be
    called frequently, so it must be implemented efficiently.
*/

/*
    Plan Outline:
    > The addRecord function has to add a new student record to the collection. In order to do so,
    a new spot in heap memory must be created for it, meaning that a new listNode has to be assigned
    to the tail's next property.
        - The tail will keep track of the last item in the studentCollection, which will allow for easier
        access to add a new record to it.
        - Each time a new record is added, the tail must point to it
        - The tail's next property must then point to NULL.
    > The averageRecord function needs to return the average of all the student records in studentCollection.
        - In order to do this, I must traverse the linked list, access each node's grade and add it to the sum.
        A count of all the grades must also be kept in order to divide the sum by the count and return the
        average.
        - The loop must continue as long as the tail of the linked list hasn't been reached.
            - I will know if it has been reached because its next property will be pointing to NULL,
            so this will be the condition to check in a while loop.
            - At the end of each repetition of the loop, the variable currentRecord must point to the
            next node in the linked list.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

struct listNode
{
    int studentNumber;
    int grade;
    listNode * next;
};

typedef listNode * studentCollection;

void addRecord(studentCollection &studentRecords, int studentNumber, int grade)
{
    // tailStudentRecord->next = new listNode;
    // tailStudentRecord = tailStudentRecord->next;
    // tailStudentRecord->studentNumber = studentNumber;
    // tailStudentRecord->grade = grade;
    // tailStudentRecord->next = NULL;

    listNode * newRecord = new listNode;
    newRecord->studentNumber = studentNumber;
    newRecord->grade = grade;

    newRecord->next = studentRecords;
    studentRecords = newRecord;
    newRecord = NULL;
}

double averageRecord(studentCollection studentRecords)
{
    if (studentRecords == NULL)
        return 0;
        
    double sum = 0;
    int numberOfRecords = 0;
    listNode * currentRecord = studentRecords;

    while (currentRecord != NULL)
    {
        numberOfRecords++;
        sum += currentRecord->grade;
        currentRecord = currentRecord->next;
    }

    return (sum / numberOfRecords);
}

int main() {
    // // Create the first item of the linked list
    // studentCollection headStudentRecord = new listNode;
    // headStudentRecord->grade = 98;
    // headStudentRecord->studentNumber = 1000;
    // headStudentRecord->next = NULL;
    // studentCollection tailStudentRecord = headStudentRecord;

    studentCollection studentRecords = NULL;

    listNode * node1 = new listNode;
    node1->studentNumber = 1001;
    node1->grade = 78;
    listNode * node2 = new listNode;
    node2->studentNumber = 1012;
    node2->grade = 93;
    listNode * node3 = new listNode;
    node3->studentNumber = 1076;
    node3->grade = 85;

    studentRecords = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    
    return 0;
}
