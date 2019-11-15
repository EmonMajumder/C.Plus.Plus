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

        //Open the file to read
        inStream.open(inputfileName.c_str());

        if (!inStream.fail( ))
        {
            //Function Call for getting output file name
            outputfileName = Getoutputfilename(&inputfileName);

            //Library error hanler from ifstream and ofstream
            outStream.exceptions(ofstream::failbit|ofstream::badbit);

            try
            {
                //Open Output file for writing.
                outStream.open(outputfileName.c_str( ),ios::app);

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
            catch(ofstream::failure e)
            {
                cerr << e.what();

                //Exit the program.
                exit(1);
            }
        }
        else
        {
            //If error happens to open the file to write, throw custom error.
            throw customerror;
        }
        //Close input file
        inStream.close( );

        //Close output file
        outStream.close( );
    }
    catch(Err customerror)
    {
        cout << customerror.message << endl;
        exit(1);
    }
    //Default error thrown to this catch block.
    catch (...)
    {
        cout << "Error!!!" << endl;
    }
    return 0;
}


