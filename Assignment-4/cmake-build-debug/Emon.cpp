#include <iostream>
#include <fstream>
#include <cstdlib>
#include <regex>
#include "Validateinput.h"
using namespace std;

int main() {
    ifstream inStream;
    ofstream outStream;
    char next;
    string nextstr;
    string inputfileName;
    string outputfileName;
    regex r (R"(^\S+(\s\S+)*$)");
    string pre = "<PRE>\n";
    string endpre = "\n</PRE>\n";

    //Custom Error
    Err customerror;

    string ask = "Enter FileName:";
    string errormessage = "Invalid input for Filename. FileName should contain no space at the end or begining.";

    cout << "This program is capable of reading .cpp and .txt type file.\n"
            "For filename ending with '.cpp', filename extention is not needed in input.\n"<< endl;
    try
    {
        //Function call for user input for filename.
        inputfileName = Validate(&ask,&errormessage,&r);

        //Library error hanler from ifstream and ofstream
        inStream.exceptions(ifstream::failbit|ifstream::badbit);

        try
        {
            //Open the file to read
            inStream.open(inputfileName.c_str( ));
        }
        catch(ifstream::failure e)
        {
            cerr << e.what();

            //Exit the program.
            exit(1);
        }

        //Function Call for getting output file name
        outputfileName = Getoutputfilename(&inputfileName);

        try
        {
            //Open Output file for writing.
            outStream.open(outputfileName.c_str( ),ios::app);

            if (!outStream.fail( ))
            {
                //Write <PRE> to output file
                outStream << pre;

                //Start getting characters from inputfile
                inStream.get(next);

                //Loop for getting all characters from input file until end of file is reached.
                while(!inStream.eof())
                {
                    //Call to function Replace to check if it is replacable character and replace.
                    nextstr = Replace(&next);

                    //Write to output file.
                    outStream << nextstr;

                    //Get the next character from inputfile
                    inStream.get(next);
                }

                outStream << endpre;
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
        //Close output file
        outStream.close( );

        //Close input file
        inStream.close( );
    }
    //Default error thrown to this catch block.
    catch (...)
    {
        cout << "Error!!!" << endl;
    }
    return 0;
}


