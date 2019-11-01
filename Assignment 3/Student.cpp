//
// Created by W0411567 on 10/31/2019.
//
#include <iostream>
#include <cstdio>
#include <regex>
#include "Student.h"
#include <string>
using namespace std;

//Default constructor
Student::Student()
{
    this->Name = "";
    this->numCourses = 0;
    this->courseList = new string[999];
}

//Another constructor
Student::Student(string Name, int numCourses, string *courseL)
{
    this->Name = Name;
    this->numCourses = numCourses;
    this->courseList = new string[numCourses];
    *courseList = *courseL;
}

//Copy Constructor
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

//Destructor
Student::~Student()
{
    if(this->courseList!=NULL)
    {
        delete [] courseList;
    }
    cout <<"---------------------------------------- Destructor Fired !!!! ---------------------------------------"<< endl;
}

//Function for all inputs
void Student::TakeInput()
{
    string studentName;
    string CourseName;
    bool leave = false;
    regex r (R"(^\S+(\s?\S+)*$)");
    int i = 0;

    cout << "Name can not contain blankspaces at the begining or end." <<endl;
    while(true)
    {
        cout << "Your Name:";
        getline(cin,studentName);
        if (regex_match(studentName, r))
        {
            break;
        }
        else
        {
            if(studentName=="")
            {
                cout << "Please input your name." <<endl;
            }
            else
            {
                cout << "Name can not contain blankspaces at the begining or end." <<endl;
                cin.clear();
            }
        }
    }
    this->Name=studentName;

    cout << "Type 'Quit' for course name to end Course entry and continue." <<endl;
    cout << "Name can not contain blankspaces at the begining or end." <<endl;
    while(!leave)
    {
        while(true)
        {
            cout << "Course Name:";
            getline(cin,CourseName);
            if (regex_match(CourseName, r))
            {
                if(CourseName == "quit")
                {
                    leave=true;
                    break;
                }
                else
                {
                    courseList[i] = CourseName;
                    i++;
                }
            }
            else
            {
                if(studentName=="")
                {
                    cout << "Please input a course name." <<endl;
                }
                else
                {
                    cout << "Course Name can not contain blankspaces at the begining or end." <<endl;
                    cin.clear();
                }
            }
        }
    }
    numCourses = i;
}

// "=" operator overload function
Student Student::operator = (const Student& Studentin)
{
    delete[] this->courseList;
    this->courseList = new string[Studentin.numCourses];
    this->Name = Studentin.Name;
    this->numCourses = Studentin.numCourses;
    for(int i=0;i<this->numCourses;i++)
    {
        this->courseList[i]=Studentin.courseList[i];
    }
    cout << "-------------------------------------- Assignment operator Fired !!!! ----------------------------------" << endl;
    return *this;
}

//Output  operator overload
ostream& operator << (ostream &out, Student &Studentin)
{
    out << "Name :" << Studentin.Name << endl;
    for(int i=0;i<Studentin.numCourses;i++)
    {
        out << "Course Name: "<< Studentin.courseList[i] << endl;
    }
    return out;
}

//Function to make the string array null
void Student::EmptyArray()
{
    this->numCourses=0;
    this->courseList=NULL;
    cout << "----------------------------------------- Empty fired !!! ----------------------------------------- " <<endl;
}

//Accessor
string Student::GetName()
{
    return Name;
}

//Accessor
int Student::GetnumCourse()
{
    return numCourses;
}

//Accessor
string* Student::GetcourseList()
{
    return courseList;
}

//Mutator
void Student::SetName(string Name)
{
    this->Name = Name;
}

//Mutator
void Student::SetnumCourse (int num)
{
    this->numCourses = num;
}

//Mutator
void Student::SetcourseList (string* courseList)
{
    this->courseList = courseList;
}

