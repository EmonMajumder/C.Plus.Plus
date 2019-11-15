//
// Created by W0411567 on 11/14/2019.
//
#include <iostream>
#include "Validateinput.h"
#include <regex>
#include <string>
using namespace std;

//Function for user input and  validationg filename
string Validate(string *ask,string *errormessage, regex *r)
{
    string value;
    regex rex (R"(^\S+(\s\S+)*((\.cpp)|(\.txt))$)");

    //While loop for continually asking filename for invalid input
    while(true)
    {
        cout << *ask;
        getline(cin,value);

        //Regex comparism
        if (regex_match(value, *r))
        {
            if(!regex_match(value,rex))
            {
                value+=".cpp";
            }
            break;
        }
        else
        {
            //Check if no input given.
            if(value.empty())
            {
                cout << "Please input a filename." <<endl;
                cin.clear();
            }
            else
            {
                cout << *errormessage << endl;
                cin.clear();
            }
        }
    }
    return value;
}

//Function to replace the targeted character.
string Replace (char *c)
{
    //Make a string with character
    string s(1,*c);

    if(*c == '<')
    {
        return "&lt;";
    }
    else if(*c == '>')
    {
        return "&gt;";
    }
    else
    {
        return s;
    }
}

//Function to get output filename based on input filename
string Getoutputfilename(string *inputfilename)
{
    string str(*inputfilename);
    int namesize;
    int dotposition = 0;

    namesize = str.length();
    char carray[namesize+1];

    //Copy string str to character array carray
    strcpy(carray,str.c_str());

    for(int i=0; i<(namesize+1);i++)
    {
        if(carray[i] =='.')
        {
            dotposition = i;
        }
    }

    //Erase filaname extension from input filename
    str.erase(str.begin()+dotposition,str.end());

    //Filename with '.html extension'
    str+=".html";

    return str;
}