// #include stdafx.
#include <string>
#include <iostream>
#include <sstream>
#include "roster.h"
#include "degree.h"

using namespace std;

void printPersonalInfo() {

    cout << "Sean Mccorkle" << endl;
    cout << "Student ID #009964461" << endl;
    cout << "C867 - Scripting and Programming - Applications" << endl;
    cout << "Written in cpp" << endl << endl;
}


// start calling functions

int main() {

    cout << "Personal: " << endl << endl;
    printPersonalInfo();

    DegreeProgram program;
    Roster classRoster;

    string studentData[5] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK","A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY","A5,Sean,Mccorkle,seanspy7@gmail.com,20,33,43,37,SOFTWARE" };

    int age; int daysInCourse1; int daysInCourse2; int daysInCourse3;
    string studentID; string firstName; string lastName; string emailAddress;

    string stringArray[9];
    string cell;

    for (int index = 0; index < 5; index++) {

        int index2 = 0;  // reset

        string lineString = studentData[index];
        istringstream ss(lineString);

        while (getline(ss, cell, ',')) {
            stringArray[index2] = cell;
            index2++;
        }

        // studentID = stringArray[0];
        // firstName = stringArray[1];
        // lastName= stringArray[2];
        
        
        
        
        emailAddress= stringArray[3];

        // age = std::stoi(stringArray[4]);
        // daysInCourse1= std::stoi(stringArray[5]);
        // daysInCourse2 = std::stoi(stringArray[6]);
        // daysInCourse3 = std::stoi(stringArray[7]);

        if (stringArray[8] == "SOFTWARE") {
            program = SOFTWARE;
        }

        if (stringArray[8] == "NETWORK") {
            program = NETWORK;
        }

        if (stringArray[8] == "SECURITY") {
            program = SECURITY;
        }


        // now call add() function

        classRoster.add(stringArray[0], stringArray[1], stringArray[2], stringArray[3],
            std::stoi(stringArray[4]), std::stoi(stringArray[5]), std::stoi(stringArray[6]),
            std::stoi(stringArray[7]), program);
    }

    cout << "All students:" << endl << endl;

    classRoster.printAll();

    cout << endl;
    classRoster.printInvalidEmails();

    cout << endl;

    cout << "Average days for each student to complete their course: " << endl << endl;;

    for (int index = 0; index < 5; index++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudentIDWithPointer(index));
    }

    cout << endl << endl;

    cout << "All students in the SOFTWARE program: " << endl << endl;

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    cout << "All students except #A3: " << endl << endl;

    classRoster.printAll();

    cout << "Attempting to delete student #A3: " << endl << endl;
    classRoster.remove("A3");
}