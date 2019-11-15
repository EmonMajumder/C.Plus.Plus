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

    try
    {
        cout << "This program is capable of reading .cpp and .txt type file.\n"
                "For filename ending with '.cpp', filename extention is not needed in input.\n"<< endl;

        //Function call for user input for filename.
        inputfileName = ValidateInputFilename(&askin,&errormessage,&r);

        //Call to function to read the file
        filecontentstring = Readfile(&inputfileName);

        //Function Call for getting output file name
        //outputfileName = Getoutputfilename(&inputfileName);

        cout << "\nFor Output html filename, filename with '.html' or without'.html' extension both are accepted.\n"
                "Program will append to output file if it already exists, otherwise create one."<< endl;

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


