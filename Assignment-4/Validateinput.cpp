//
// Created by W0411567 on 11/14/2019.
//
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "Validateinput.h"
using namespace std;

//Function for user input and  validationg filename
string ValidateInputFilename(string *ask,string *errormessage, regex *r)
{
    string value;
    ifstream inStream;
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

            inStream.open(value.c_str());
            if (!inStream.fail( ))
            {
                inStream.close();
                break;
            }
            else
            {
                cout << "File was not found. Please Check file name." << endl;
                cin.clear();
            }
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

string ValidateOutputFilename(string *ask,string *errormessage, regex *r)
{
    string value;
    regex rout (R"(^\S+(\s\S+)*\.html$)");

    //While loop for continually asking filename for invalid input
    while(true)
    {
        cout << *ask;
        getline(cin,value);

        //Regex comparism
        if (regex_match(value, *r))
        {
            if(!regex_match(value,rout))
            {
                value+=".html";
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

string Readfile(string *inputfileName)
{
    ifstream inStream;
    string fname(*inputfileName);
    char next;
    string nextstr;
    string content;
    //Custom Error
    Err customerror;

    try
    {
        //Open the file to read
        inStream.open(fname.c_str());

        if (!inStream.fail( ))
        {
            //Start getting characters from inputfile
            inStream.get(next);

            //Loop for getting all characters from input file until end of file is reached.
            while (!inStream.eof()) {

                //Call to function Replace to check if it is replacable character and replace.
                nextstr = Replace(&next);

                //Add to string.
                content += nextstr;

                //Get the next character from inputfile
                inStream.get(next);
            }
        }
        else
        {
            //If error happens to open the file to write, throw custom error.
            throw customerror;
        }
    }
    catch(Err customerror)
    {
        cout << customerror.message << endl;
        exit(1);
    }
    catch (...)
    {
        cout << "Error!!!" << endl;
    }

    //Close input file
    inStream.close( );

    return content;
}

void Writefile(string *filecontentstring, string *outfileName)
{
    ofstream outStream;
    string outputfileName(*outfileName);

    //Library error hanler from ifstream and ofstream
    outStream.exceptions(ofstream::failbit|ofstream::badbit);

    try
    {
        //Open Output file for writing.
        outStream.open(outputfileName.c_str( ),ios::app);

        //Write <PRE> to output file
        outStream << "<PRE>\n";

        //Write string to file
        outStream << *filecontentstring;

        //Write </PRE> to output file
        outStream << "\n</PRE>";
    }
    catch(ofstream::failure e)
    {
        cerr << e.what();

        //Exit the program.
        exit(1);
    }
    catch (...)
    {
        cout << "Error!!!" << endl;
    }

    //Close the file after write
    outStream.close();
}