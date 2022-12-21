// #include stdafx.h
#include <iostream>
#include <string>
#include <iomanip>

#include "roster.h"
#include "degree.h"

using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program)

{
    // threeCoursesArray: [30,35,40]
    int threeCoursesArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    // for loop is needed because 
    // the current position in classRosterArray isnt stored

    for (int index = 0; index < 5; index++) {

        // [nullptr, nullptr, nullptr, nullptr,] becomes 
        // [StudentObj, nullptr, nullptr, nullptr,]

        if (classRosterArray[index] == nullptr) {
            classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, threeCoursesArray, program);
            break; // break as soon as [nullptr] is changed to the [Student["Sean", "Mccorkle"]
        }
    }
}

// dont assign index, just take it from the function call

string Roster::getStudentIDWithPointer(int index) {
    return classRosterArray[index]->getStudentID();
}

void Roster::remove(string studentID) {

    // start at false
    bool b;
    b = false;

    for (int index = 0; index < 5; index++) {

        // dont function call on null pointers
        if (classRosterArray[index] != nullptr) {

            // keep looping until "A3" student ID is found, then delete it
            if (classRosterArray[index]->getStudentID() == studentID) {
                b = true;
                delete classRosterArray[index];
                classRosterArray[index] = nullptr;
            }
        }
    }   // end for loop

    // if nothing got deleted, it was already a null pointer

    if (b == false) {
        cout << "Cant delete ID  #" << studentID << ", ID not found. Only current students have an ID."
            << endl;
    }
}

void Roster::printAll() {

    int index;

    for (index = 0; index < 5; index++) {

        if (classRosterArray[index] != nullptr) {
            classRosterArray[index]->print();
            cout << endl;
        }
    }
}


void Roster::printAverageDaysInCourse(string studentID) {

    // int pointer;

    // cant save the pointer from the last function
    // so it has to re-loop until the student ID is found

    for (int index = 0; index < 5; index++) {

        if (classRosterArray[index]->getStudentID() == studentID) {
            // pointer = index;

            cout << fixed << setprecision(1);

            cout << "Student ID #" << studentID << " has an average of "
                << classRosterArray[index]->getAverageDaysInCourses()
                << " days to complete each of his courses." << endl;
            // break;
        }
    }

    // cout << "Student ID #" << classRosterArray[pointer]->getStudentID() << " "
    // << "has an average of "<< classRosterArray[pointer]->getAverageDaysInCourses()
    // << " days to complete each of his courses." << endl;
}

// {program: SOFTWARE}
// printByDegreeProgram(SOFTWARE)



void Roster::printByDegreeProgram(DegreeProgram softwareNetworkSecurity) {

    for (int index = 0; index < 5; index++) {

        if (classRosterArray[index]->getDegreeProgram() == softwareNetworkSecurity) {
            classRosterArray[index]->print();
            cout << endl;
        }
    }
}

void Roster::printInvalidEmails() {

    cout << "These emails are all invalid, check for spaces, a missing period or a missing @ mark."
        << endl << endl;

    for (int index = 0; index < 5; index++) {

        if (classRosterArray[index]->checkEmail() == false) {

            // print the invalid email in its current form
            cout << classRosterArray[index]->getEmail() << endl;
        }
    }
}


// destructor

// Roster::~Roster() {

//     for (int index = 0; index < 5; index++) {
//         delete classRosterArray[index];
//         classRosterArray[index] = nullptr;
//     }
// }



