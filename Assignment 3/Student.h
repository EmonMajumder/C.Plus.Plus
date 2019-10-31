//
// Created by W0411567 on 10/31/2019.
//

#ifndef ASSIGNMENT_3_STUDENT_H
#define ASSIGNMENT_3_STUDENT_H
#include <string>
using namespace std;


class Student {
private:
    string Name;
    int numCourses;
    string *courseList = new string[numCourses];

public:
    Student();
    Student(string Name, int numCourses, string Courses[]);
    Student(Student& Studentin);
    Student operator = (const Student& Studentin);
    friend ostream& operator << (ostream& output, Student& Studentin);
    ~Student();

    Student TakeInput ();
    void EmptyArray();
    string GetName();
    int GetnumCourse();
    string* GetcourseList();
    void SetName(string Name);
    void SetnumCourse(int num);
    void SetcourseList(string* courseList);
};



#endif //ASSIGNMENT_3_STUDENT_H
