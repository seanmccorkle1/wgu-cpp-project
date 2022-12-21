// #include stdafx.h
#include <iostream>
#include <iomanip>
#include <string>

#include "student.h"
#include "degree.h"

using namespace std;


Student::Student(string studentIDParam, string firstNameParam, string lastNameParam,
    string emailParam, int ageParam, int threeCoursesArrayParam[3], DegreeProgram programParam)
{

    studentID = studentIDParam;
    firstName = firstNameParam;
    lastName = lastNameParam;
    emailAddress = emailParam;
    age = ageParam;


    for (int index = 0; index < 3; index++) {
        threeCoursesArray[index] = threeCoursesArrayParam[index];
    }

    program = programParam;
}


bool Student::checkEmail() {

    // invalid if no @ found OR no "." found
    // @gmail.com

    if (emailAddress.find("@") == string::npos || emailAddress.find(".") == string::npos) {
        return false;
    }
    // if a space is found, return false
    if (emailAddress.find(" ") != string::npos) {
        return false;
    }

    // emailAddress is valid if it gets here
    return true;
}


string Student::getDegreeProgram(string str) {

    if (program == SECURITY) {
        return "SECURITY";
    }

    else if (program == NETWORK) {
        return "NETWORK";
    }
    else return "SOFTWARE";

}


void Student::setAge(int newAge) { age = newAge; }

int Student::getAge() { return age; }

float Student::getAverageDaysInCourses() {
    int index;
    float average;

    // have to start at 0, which is an integer
    int sum = 0;

    for (index = 0; index < 3; index++) {
        sum += threeCoursesArray[index];
    }

    // make both decimals to make the result a decimal
    average = static_cast<float>(sum) / 3.0;
    return average;
}

void Student::print() {

    int index;
    string s = "asd";

    cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last name: " << lastName <<
        "\t" << "Age: " << age << "\t" << "daysInCourse: {";

    for (int index = 0; index < 3; index++) {
        cout << threeCoursesArray[index] << ", ";
    }

    cout << "}";
    cout << "\t";

    cout << "Degree program: " << getDegreeProgram(s) << endl;
}

int* Student::getDaysInCourse() { return threeCoursesArray; }

void Student::setDaysInCourse(int* threeCoursesArrayParam) {
    for (int index = 0; index < 3; index++) {
        threeCoursesArray[index] = threeCoursesArrayParam[index];
    }
}

void Student::setDegreeProgram(DegreeProgram newProgram) { program = newProgram; }


DegreeProgram Student::getDegreeProgram() { return program; }

void Student::setEmail(string newEmail) { emailAddress = newEmail; }
string Student::getEmail() { return emailAddress; }

void Student::setFirstName(string newFirstName) { firstName = newFirstName; }
string Student::getFirstName() { return firstName; }

void Student::setLastName(string newLastName) { lastName = newLastName; }
string Student::getLastName() { return lastName; }

void Student::setStudentID(string newStudentID) { studentID = newStudentID; }
string Student::getStudentID() { return studentID; }
