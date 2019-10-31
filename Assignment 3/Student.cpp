//
// Created by W0411567 on 10/31/2019.
//
#include <iostream>

#include <cstdio>
#include "Student.h"
using namespace std;

Student::Student()
{
    this->Name = "";
    this->numCourses = 0;
    this->courseList = NULL;
}

Student::Student(string Name, int numCourses, string* courseList)
{
    this->Name = Name;
    this->numCourses = numCourses;
    this->courseList = courseList;
}
Student::Student(Student& Studentin)
{
    this->Name = Studentin.GetName();
    this->numCourses = Studentin.GetnumCourse();
    this->courseList = Studentin.GetcourseList();
    Studentin.~Student();
}

Student::~Student()
{
    if(this->courseList!=NULL)
    {
        delete [] this-> courseList;
    }
}

Student Student::TakeInput()
{
    Student student;
    string CourseName;
    string studentName;
    int i =0;
    char response;

    while(true)
    {
        cout << "Your Name:";
        cin >> studentName;
        if(studentName != "")
        {
            student.Name = studentName;
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }

    while(true)
    {
        while(true)
        {
            cout << "Course Name:" ;
            cin >> CourseName;
            if(CourseName != "")
            {
                student.courseList[i] = CourseName;
                break;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
        }
        cout << "More Course?(Y/N):";
        cin >> response;
        if(response == 'N')
        {
            break;
        }
        else if(response == 'Y')
        {
            i++;
        }
        else
        {
            cout << "Response was not Clear. Assuming you have more course left." << endl;
            i++;
        }
    }
    student.numCourses = i+1;
    return student;
}
