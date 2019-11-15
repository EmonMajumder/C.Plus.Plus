#include <iostream>
#include <fstream>
#include <cstdlib>
#include <regex>
#include "Validateinput.h"
using namespace std;

int main() {
    string inputfileName;
    string outputfileName;
    string filecontentstring;

    regex r (R"(^\S+(\s\S+)*$)");

    string askin = "Enter Read FileName:";
    string askout = "Enter Write FileName:";
    string errormessage = "Invalid input for Filename. FileName should contain no space at the end or begining.";

    cout << "This program is capable of reading .cpp and .txt type file.\n"
            "For filename ending with '.cpp', filename extention is not needed in input.\n"<< endl;
    try
    {
        //Function call for user input for filename.
        inputfileName = ValidateInputFilename(&askin,&errormessage,&r);

        //Call to function to read the file
        filecontentstring = Readfile(&inputfileName);

        //Function Call for getting output file name
        //outputfileName = Getoutputfilename(&inputfileName);

        //Ask user for Output file Name
        outputfileName = ValidateOutputFilename(&askout,&errormessage,&r);

        //Call function to write to the file
        Writefile(&filecontentstring,&outputfileName);
    }
    //Default error thrown to this catch block.
    catch (...)
    {
        cout << "Error!!!" << endl;
    }
    return 0;
}


