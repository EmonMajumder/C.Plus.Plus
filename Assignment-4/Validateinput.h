//
// Created by W0411567 on 11/14/2019.
//

#ifndef ASSIGNMENT_4_VALIDATEINPUT_H
#define ASSIGNMENT_4_VALIDATEINPUT_H
#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

//Custom error
struct Err
{
    const  char* message;
    Err() :  message("Error!!! Could not open file to read."){}
};

string ValidateInputFilename(string *ask,string *errormessage,  regex *r);
string ValidateOutputFilename(string *ask,string *errormessage, regex *r);
string Replace (char *c);
string Getoutputfilename(string *inputfilename);
string Readfile(string *inputfilename);
void Writefile(string *filecontentstring, string *outfileName);



#endif //ASSIGNMENT_4_VALIDATEINPUT_H
