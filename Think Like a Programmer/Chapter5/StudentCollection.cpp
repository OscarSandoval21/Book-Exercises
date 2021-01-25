#include <iostream>
#include <string>
#include "StudentCollection.h"
using std::cout;
using std::cin;
using std::string;

StudentCollection::StudentCollection()
{
    listHead = NULL;
}

StudentCollection::StudentCollection(const StudentCollection &original)
{
    listHead = copiedList(original.listHead);
}

StudentCollection::~StudentCollection()
{
    deleteList(listHead);
}

void StudentCollection::deleteList(studentList &listHead)
{
    listNode * nodeToDelete = NULL;
    while (listHead != NULL)
    {
        nodeToDelete = listHead;
        listHead = listHead->next;
        delete nodeToDelete;
    }
}

StudentCollection::studentList StudentCollection::copiedList(const studentList originalList)
{
    if (originalList == NULL)
        return NULL;

    studentList newList = new listNode;
    newList->studentData = originalList->studentData;
    listNode * oldCurrent = originalList->next;
    listNode * newCurrent = newList;

    while (oldCurrent != NULL)
    {
        newCurrent->next = new listNode;
        newCurrent = newCurrent->next;
        newCurrent->studentData = oldCurrent->studentData;
        oldCurrent = oldCurrent->next;
    }
    newCurrent->next = NULL;

    return newList;
}

void StudentCollection::addRecord(StudentRecord newStudent)
{
    listNode * newRecord = new listNode;
    newRecord->studentData = newStudent;
    newRecord->next = listHead;
    listHead = newRecord;
}

StudentRecord StudentCollection::recordWithNumber(int studentID)
{
    listNode * currentNode = listHead;

    while (currentNode != NULL && currentNode->studentData.getStudentID() != studentID)
        currentNode = currentNode->next;

    if (currentNode != NULL)
        return currentNode->studentData;
    else
    {
        StudentRecord dummyRecord("", -1, -1);
        return dummyRecord;
    }
    
}

void StudentCollection::removeRecord(int studentID)
{
    listNode * nodeToDelete = listHead;
    listNode * trailingNode = NULL;

    while (nodeToDelete != NULL && nodeToDelete->studentData.getStudentID() != studentID)
    {
        trailingNode = nodeToDelete;
        nodeToDelete = nodeToDelete->next;
    }
    

    if (nodeToDelete == NULL)
        return;


    if (trailingNode == NULL)
        listHead = listHead->next;
    else
        trailingNode->next = nodeToDelete->next;

    delete nodeToDelete;
}

StudentCollection& StudentCollection::operator=(const StudentCollection &rhs)
{
    if (this != &rhs)
    {
        deleteList(listHead);
        listHead = copiedList(rhs.listHead);
    }
    return *this;
}