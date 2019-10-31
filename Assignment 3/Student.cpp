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
    this->courseList = new string[numCourses];
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
    Name = Studentin.Name;
    numCourses = Studentin.numCourses;
    for(int i=0;i<Studentin.courseList->size();i++)
    {
        courseList[i]=Studentin.courseList[i];
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
    int i =0;
    char response;
    while(true)
    {
        cout << "Your Name:";
        cin >> studentName;
        if(studentName != "")
        {
            Name = studentName;
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
    bool loopbreaker = true;
    while(loopbreaker)
    {
        while(true)
        {
            cout << "Course Name:" ;
            cin >> CourseName;
            if(CourseName != "")
            {
                courseList[i] = CourseName;
                break;
            }
            else
            {
                cout << "Invalid input." << endl;
                cout << "Want do leave?(Y/N):" ;
                cin >> response;
                if(response != 'N')
                {
                    loopbreaker = false;
                    break;
                }
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
    numCourses = i+1;
}

Student Student::operator = (const Student& Studentin)
{
    Studentin.~Student();

    Name = Studentin.Name;
    numCourses = Studentin.numCourses;
    for(int i=0;i<Studentin.courseList->size();i++)
    {
        courseList[i]=Studentin.courseList[i];
    }
    cout << "----------------------------------------- Assignment operator Fired !!!! ----------------------------------------" << endl;
    return *this;
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



