#include <iostream>
#include "Student.h"
#include <regex>
using namespace std;

int main() {

    char response;
    string studentName;
    regex r (R"(^\S+(\s?\S+)*$)");

    while(true)
    {
        Student student1;
        student1.TakeInput();
        cout << student1;
        Student student2 = student1;

        while(true)
        {
            cout << "Your Name:";
            getline(cin,studentName);
            if (regex_match(studentName, r))
            {
                break;
            }
            else
            {
                if(studentName=="")
                {
                    cout << "Please input a name." <<endl;
                    cin.clear();
                }
                else
                {
                    cout << "Name can not contain blankspaces at the begining or end." <<endl;
                    cin.clear();
                }
            }
        }
        student2.SetName(studentName);

        //Print student2 informations
        cout << student2;

        student1.EmptyArray();
        cout << student1;
        cout << student2;
        Student student3;
        student3 = student2;
        cout << student3;
        cout << "Keep going?(Y/N):" ;
        cin >> response;
        if(response != 'Y')
        {
            break;
        }
    }
    return 0;
}