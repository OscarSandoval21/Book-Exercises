#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

class StudentRecord
{
    private:
        string name;
        int grade;
        int studentID;
        
    public:
        StudentRecord();
        StudentRecord(string newName, int newGrade, int newID);
        ~StudentRecord();
        void setName(string newName);
        string getName();
        void setGrade(int newGrade);
        int getGrade();
        void setStudentID(int newID);
        int getStudentID();
        string letterGrade();
        bool isValidGrade(int grade);
};

#endif