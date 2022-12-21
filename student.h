#pragma once

#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:

    Student(string studentID, string firstName, string lastName, string emailAddress,
        int age, int* threeCoursesArray, DegreeProgram program);

    void print();
    float getAverageDaysInCourses();


    int getAge();
    void setAge(int newAge);

    int* getDaysInCourse();
    void setDaysInCourse(int* threeCoursesArrayParam);

    string getEmail();
    void setEmail(string newEmail);
    bool checkEmail();

    string getFirstName();
    void setFirstName(string newFirstName);

    string getLastName();
    void setLastName(string newLastName);

    string getStudentID();
    void setStudentID(string newStudentID);

    string getDegreeProgram(string str);
    DegreeProgram getDegreeProgram();

    void setDegreeProgram(DegreeProgram newProgram);

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;

    int age;
    int threeCoursesArray[3] = { 50, 50, 50 };

    DegreeProgram program;
};