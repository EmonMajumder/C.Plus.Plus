#include <iostream>
#include "Rational.cpp"

//Main function
int main() {

    Rational r;
    string input;
    Rational num1;
    Rational num2;
    Rational inputnum;

    //For loop to ask user for input.
    for(int i=1;i<=2;i++)
    {
        if(i==1)
        {
            cout <<"Your first Number :";
        }
        else
            cout <<"Your second Number :";

        //While loop to confirm a valid input from user.
        while(true)
        {
            if(cin >> inputnum)
            {
                cout << "Invalid number."<<endl;
                cout << "Input number :";
            } else
                break;
        }
        if(i==1)
        {
            num1 = inputnum;
        }
        else
            num2 = inputnum;
    }

//Perform operatins with rational numbers.

    if(num1 == num2)
    {
        cout<<"Numbers are equal"<<endl;
    }
    else if(num1 < num2)
    {
        cout<<"First number is lesser than second number"<<endl;
    }
    else if(num1 > num2)
    {
        cout<<"First number is greater than second number"<<endl;
    }

    r = num1+num2;
    cout<<"Addition :";
    cout<<r<<endl;

    r = num1-num2;
    cout<<"Substraction :";
    cout<<r<<endl;

    r = num1*num2;
    cout<<"Multiplication :";
    cout<<r<<endl;

    r = num1/num2;
    cout<<"Division :";
    cout<<r<<endl;

    num1+=num2;
    cout<<"Increment a number by other number :";
    cout<<num1<<endl;

    return 0;
}


//---------------------------------------------------------------------------------------------------

//int main() {
//
//    Rational r;
//    string input;
//    Rational num1;
//    Rational num2;
//    Rational inputnum;
//    string Operator;
//    int operation;
//
//    for(int i=1;i<=3;i++)
//    {
//        if(i==1)
//            cout <<"Your first Number :";
//        else if(i==2)
//            cout <<"Your operator:";
//        else
//            cout <<"Your second Number :";
//
//        if(i==2)
//        {
//            cin >> Operator;
//            if(Operator=="==")
//            {
//                operation=1;
//            }
//            else if(Operator=="<")
//            {
//                operation=2;
//            }
//            else if(Operator==">")
//            {
//                operation=3;
//            }
//            else if(Operator=="+")
//            {
//                operation=4;
//            }
//            else if(Operator=="-")
//            {
//                operation=5;
//            }
//            else if(Operator=="*")
//            {
//                operation=6;
//            }
//            else if(Operator=="/")
//            {
//                operation=7;
//            }
//        }
//
//        else
//        {
//            while(true)
//            {
//                if(cin >> inputnum)
//                {
//                    cout << "Invalid number."<<endl;
//                    cout << "Input number :";
//                } else
//                    break;
//            }
//        }
//        if(i==1)
//            num1 = inputnum;
//        else if(i==3)
//            num2 = inputnum;
//    }
//
//    switch (operation)
//    {
//        case 1:
//            if(num1 == num2)
//            {
//                cout<<"Numbers are equal"<<endl;
//            }
//            break;
//        case 2:
//            if(num1 < num2)
//            {
//                cout<<"First number is less than second number"<<endl;
//            }
//            break;
//        case 3:
//            if(num1 > num2)
//            {
//                cout<<"First number is more than second number"<<endl;
//            }
//            break;
//        case 4:
//            r = num1+num2;
//            break;
//        case 5:
//            r = num1-num2;
//            break;
//        case 6:
//            r = num1*num2;
//            break;
//        case 7:
//            r = num1/num2;
//            break;
//    }
//    cout<<r<<endl;
//    return 0;
//}
