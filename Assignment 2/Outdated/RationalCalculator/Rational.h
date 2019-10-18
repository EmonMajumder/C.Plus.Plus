//
// Created by W0411567 on 10/17/2019.
//

#ifndef RATIONALCALCULATOR_RATIONAL_H
#define RATIONALCALCULATOR_RATIONAL_H

#include <fstream>
#include <vector>
using namespace std;
#ifndef RATIONAL_NUMBER_CALCULATOR_RATIONAL_H
#define RATIONAL_NUMBER_CALCULATOR_RATIONAL_H

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational();

    Rational(int num);

    Rational(int num, int num2);

    int getnumerator();

    int getdenominator();

    void setnumerator(int num);

    void setdenominator(int num);

    friend bool operator == (Rational &, Rational &);
    friend bool operator < (Rational &, Rational &);
    friend bool operator > (Rational &, Rational &);
    friend Rational operator + (Rational &, Rational &);
    friend Rational operator - (Rational &, Rational &);
    friend Rational operator / (Rational &, Rational &);
    friend Rational operator * (Rational &, Rational &);
    friend void operator += (Rational &r1, Rational &r2);
    friend ostream & operator << (ostream &out, Rational &r);
    friend bool operator >> (istream &in, Rational &rationalnum);
};

void normalize(Rational &r);
//Function to get the numerator and denominator from the expressions like a/b.
vector<string> split(const string& input, const string& regexoperator);

#endif //RATIONAL_NUMBER_CALCULATOR_RATIONAL_H
#endif //RATIONALCALCULATOR_RATIONAL_H
