//
// Created by W0411567 on 10/31/2019.
//

#ifndef ASSIGNMENT_3_STUDENT_H
#define ASSIGNMENT_3_STUDENT_H
#include <string>
using namespace std;


class Student {
public:
    string Name;
    int numCourses;
    string *courseList = new string[numCourses];

    Student();
    Student(Student& Studentcpy);
};



#endif //ASSIGNMENT_3_STUDENT_H
