#pragma once

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Roster {

public:

    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program);

    string getStudentIDWithPointer(int index);
    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram);

    void remove(string studentID);


private:
    // new Array(5).fill(0)
    Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};