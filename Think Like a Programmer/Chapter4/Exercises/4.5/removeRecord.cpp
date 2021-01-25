/*
    4-5. Write a function (removeRecord) that takes a pointer to a studentCollection and a
    student number and that removes the record with that student number from
    the collection.
*/

/*
    Plan Outline:
    > The function removeRecord will need to sequentially traverse through the linked list
    searching for the student number until it finds it. Once found, the record needs to be removed.
    However, removing it will cause a gap on the linked list to be made, so in order to avoid this,
    I will need to link the previous record to the next record, in relation to the one being removed.
    > Because there's no way to access a node's previous node, only its next node, then searching
    for the node with the student number that matches will not allow me to link the previous and next
    nodes to one another. Therefore, a better plan is to search for a node's next node's student number.
        - if (node->next->studentNumber == studentNumber) {remove record from collection, link previous
        and next nodes to continue the linked list}.
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
    listNode * newRecord = new listNode;
    newRecord->studentNumber = studentNumber;
    newRecord->grade = grade;

    newRecord->next = studentRecords;
    studentRecords = newRecord;
    newRecord = NULL;
}

void removeRecord(studentCollection &studentRecords, int studentNumber)
{
    // Special case, no records in list
    if (studentRecords == NULL)
    {
        cout << "There are no records in the list!\n";
        return;
    }

    // Start with the first record in the linked list
    listNode * currentRecord = studentRecords;
    listNode * recordToDelete;

    // Special case, when the record to be deleted is the first one
    if (studentRecords->studentNumber == studentNumber)
    {
        recordToDelete = studentRecords;
        studentRecords = studentRecords->next;
        delete recordToDelete;
        recordToDelete = NULL;
        return;
    }

    // When the record to be removed is not the first record
    while (currentRecord->next != NULL && currentRecord->next->studentNumber != studentNumber)
        currentRecord = currentRecord->next;

    // If the next node is NULL, then we didn't find the record in the list
    if (currentRecord->next == NULL)
    {
        cout << "There was no student record with that student number.\n";
        return;
    }
    
    recordToDelete = currentRecord->next;
    cout << "Will delete record with student number: " << recordToDelete->studentNumber << "\n";
    // Connect the records so that there is no gap when the record is removed from the linked list
    currentRecord->next = recordToDelete->next;
    delete recordToDelete;
    recordToDelete = NULL;
}

void deleteLinkedList(studentCollection &studentRecords)
{
    listNode * temp = studentRecords;

    cout << "studentRecords: " << studentRecords << "\n";
    cout << "temp: " << temp << "\n";

    while (studentRecords != NULL)
    {
        studentRecords = studentRecords->next;
        delete temp;
        temp = studentRecords;
    }

    cout << "studentRecords: " << studentRecords << "\n";
    cout << "temp: " << temp << "\n";
}

void printRecords(studentCollection studentRecords)
{
    while (studentRecords != NULL)
    {
        cout << "{ " << studentRecords->studentNumber << ", " << studentRecords->grade << " }\n";
        studentRecords = studentRecords->next;
    }
}

int main() {
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

    int recordToDelete = 1001;

    cout << "All records in list:\n";
    printRecords(studentRecords);

    cout << "After removing record: " << recordToDelete << "\n";
    removeRecord(studentRecords, recordToDelete);
    printRecords(studentRecords);

    recordToDelete = 1012;
    cout << "After removing record: " << recordToDelete << "\n";
    removeRecord(studentRecords, recordToDelete);
    printRecords(studentRecords);

    recordToDelete = 1076;
    cout << "After removing record: " << recordToDelete << "\n";
    removeRecord(studentRecords, recordToDelete);
    printRecords(studentRecords);

    recordToDelete = 1012;
    cout << "After removing record: " << recordToDelete << "\n";
    removeRecord(studentRecords, recordToDelete);
    printRecords(studentRecords);

    cout << "After deleting the list:\n";
    deleteLinkedList(studentRecords);
    printRecords(studentRecords);
    
    return 0;
}
