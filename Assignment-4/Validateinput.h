//
// Created by W0411567 on 11/14/2019.
//

#ifndef ASSIGNMENT_4_VALIDATEINPUT_H
#define ASSIGNMENT_4_VALIDATEINPUT_H
#include <iostream>
#include <regex>
using namespace std;

//Custom error
struct Err
{
    const  char* message;
    Err() :  message("Error!!! Could not open file to read."){}
};

string Validate(string *ask,string *errormessage,  regex *r);
string Replace (char *c);
string Getoutputfilename(string *inputfilename);



#endif //ASSIGNMENT_4_VALIDATEINPUT_H
