/**
    CS 2150, testPostfixCalc.cpp
    Purpose: test file for PostfixCalculator class

    @author Alan Zheng (az4xfp)
    @version 1.2 02/04/2020
*/

#include <iostream>
using namespace std;

#include "postfixCalculator.h"

int main() {
	PostfixCalculator p;
    bool input = true;
    if (!input) {
        p.pushNum(1);
        p.pushNum(2);
        p.pushNum(3);
        p.pushNum(4);
        p.pushNum(5);
        p.add();
        p.add();
        p.add();
        p.add();
    }
    else {
        string token;
        cout << "Enter a postfix expression: ";
        while(cin >> token) {
            if(token == "+") {
                p.add();
            }
            else if(token == "-") {
                p.subtract();
            }
            else if(token == "*") {
                p.multiply();
            }
            else if(token == "/") {
                p.divide();
            }
            else if(token == "~") {
                p.negate();
            }
            else {
                p.pushNum(stoi(token));
            }
        }

    }
    cout << "Result is: " << p.getTopValue() << endl;
    return 0;
}