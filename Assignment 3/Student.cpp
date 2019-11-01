//
// Created by W0411567 on 10/31/2019.
//
#include <iostream>
#include <cstdio>
#include <regex>
#include "Student.h"
using namespace std;

Student::Student()
{
    this->Name = "";
    this->numCourses = 0;
    this->courseList = new string[999];
}

Student::Student(string Name, int numCourses, string *courseL)
{
    this->Name = Name;
    this->numCourses = numCourses;
    this->courseList = new string[numCourses];
    *courseList = *courseL;
}
Student::Student(const Student& Studentin)
{
    this->Name = Studentin.Name;
    this->numCourses = Studentin.numCourses;
    for(int i=0;i<Studentin.numCourses;i++)
    {
        this->courseList[i] = Studentin.courseList[i];
    }
    cout << "----------------------------------------- Copy constructor Fired ---------------------------------------" << endl;
}

Student::~Student()
{
    if(this->courseList!=NULL)
    {
        delete [] courseList;
    }
    cout << "----------------------------------------- Destructor Fired !!!! ----------------------------------------" << endl;
}

void Student::TakeInput()
{
    string CourseName;
    string studentName;
    int i = 0;
    string response;
    regex r (R"(^\S+(\s?\S+)*$)");
    while(true)
    {
        cout << "Your Name:";
        cin >> studentName;
        if(regex_match(studentName,r))
        {
            Name = studentName;
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }

    while(true)
    {
        cout << "Course Name:" ;
        cin >> CourseName;
        if(CourseName == "quit")
        {
            break;
        }
        else if(regex_match(CourseName,r))
        {
            courseList[i] = CourseName;
            i++;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    numCourses = i;
}

void Student::operator = (const Student& Studentin)
{
    delete[] this->courseList;
    this->courseList = new string[Studentin.numCourses];
    this->Name = Studentin.Name;
    this->numCourses = Studentin.numCourses;
    for(int i=0;i<this->numCourses;i++)
    {
        this->courseList[i]=Studentin.courseList[i];
    }
    cout << "----------------------------------------- Assignment operator Fired !!!! -----------------------------------" << endl;
}

ostream& operator << (ostream &out, Student &Studentin)
{
    out << "Name :" << Studentin.Name << endl;
    for(int i=0;i<Studentin.numCourses;i++)
    {
        out << "Course Name: "<< Studentin.courseList[i] << endl;
    }
    return out;
}

void Student::EmptyArray()
{
    this->numCourses=0;
    this->courseList=NULL;
    cout << "----------------------------------------- Empty fired ----------------------------------------- " <<endl;
}

string Student::GetName()
{
    return Name;
}

int Student::GetnumCourse()
{
    return numCourses;
}

string* Student::GetcourseList()
{
    return courseList;
}

void Student::SetName(string Name)
{
    this->Name = Name;
}


