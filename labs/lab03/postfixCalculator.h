/**
    CS 2150, postfixCalculator.cpp
    Purpose: header file for PostfixCalculator class

    @author Alan Zheng (az4xfp)
    @version 1.2 02/04/2020
*/

#ifndef PFCALCULATOR_H
#define PFCALCULATOR_H
#include <iostream>
#include "stack.h"
using namespace std;

class PostfixCalculator {
public:
	PostfixCalculator();
	void pushNum(int x);
	void add();
	void subtract();
	void multiply();
	void divide();
	void negate();
	int getTopValue() const;

private:
	MyStack pile;
};

#endif