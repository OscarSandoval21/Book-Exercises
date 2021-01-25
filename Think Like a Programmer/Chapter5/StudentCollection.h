#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

class StudentCollection
{
    private:
        struct listNode{
            StudentRecord studentData;
            listNode * next;
        };
        typedef listNode * studentList;
        studentList listHead;
        void deleteList(studentList &listHead);
        studentList copiedList(const studentList originalList);

    public:
        StudentCollection();
        StudentCollection(const StudentCollection &original);
        ~StudentCollection();
        void addRecord(StudentRecord newStudent);
        StudentRecord recordWithNumber(int studentID);
        void removeRecord(int studentID);
        StudentCollection& operator=(const StudentCollection &rhs);
};

#endif