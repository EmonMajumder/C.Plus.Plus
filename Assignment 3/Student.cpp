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
    string studentName;
    string CourseName;
    int i = 0;
    regex r (R"(^\S+(\s?\S+)*$)");

    cout << "Your Name:";
    while(true)
    {
        if(!(cin >> studentName))
        {
            cout << "Invalid Input" << endl;
            cout << "Your Name:";
            cin.clear();
        }
        else
            break;
    }
    this->Name=studentName;

    while(true)
    {
        cout << "Course Name:" ;
        if(!(cin >> CourseName))
        {
            cout << "Invalid Input" << endl;
            cout << "Course Name:";
            cin.clear();
        }
        else
        {
            if(CourseName == "quit")
            {
                break;
            }
            else
            {
                courseList[i] = CourseName;
                i++;
            }
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

void Student::SetnumCourse (int num)
{
    this->numCourses = num;
}

void Student::SetcourseList (string* courseList)
{
    this->courseList = courseList;
}

//Operator function to take input a string and validate the input.
bool operator >> (istream &in, string &str)
{
    string userinput;
    regex strvalid("^\\S+(\\s?\\S+)*$"); //Regex for Valid string
    in >> userinput;
    //Regex validation for valid string
    if (regex_match(userinput, strvalid))
    {
        str = userinput;
        return false;
    }
    else
    {
        return true;
    }
}
