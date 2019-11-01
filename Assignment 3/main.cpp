#include <iostream>
#include "Student.h"
using namespace std;

int main() {

    char response;
    string studentName;
    while(true)
    {
        Student student1;
        student1.TakeInput();
        cout << student1;
        Student student2 = student1;

//        cout << "Your Name:";
//        while(true)
//        {
//            if(!(cin >> studentName)) {
//                cout << "Invalid Input" << endl;
//                cout << "Your Name:";
//                cin.clear();
//            } else
//                break;
//        }
        student2.TakeInput();

        student2.SetName(studentName);
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