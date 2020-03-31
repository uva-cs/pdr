/**
    CS 2150, postfixCalculator.cpp
    Purpose: class file for PostfixCalculator class

    @author Alan Zheng (az4xfp)
    @version 1.2 02/04/2020
*/

#include <iostream>
#include "postfixCalculator.h"
using namespace std;

PostfixCalculator::PostfixCalculator() {
	MyStack pile;
}

void PostfixCalculator::pushNum(int x) {
	pile.push(x);
}
void PostfixCalculator::add() {
	int b(pile.top());
	pile.pop();
	int a(pile.top());
	pile.pop();
	pile.push(a+b);	
}
void PostfixCalculator::subtract() {
	int b(pile.top());
	pile.pop();
	int a(pile.top());
	pile.pop();
	pile.push(a-b);	
}
void PostfixCalculator::multiply() {
	int b(pile.top());
	pile.pop();
	int a(pile.top());
	pile.pop();
	pile.push(a*b);	
}
void PostfixCalculator::divide() {
	int b(pile.top());
	pile.pop();
	int a(pile.top());
	pile.pop();
	pile.push(a/b);	
}
void PostfixCalculator::negate() {
	int a(pile.top());
	pile.pop();
	pile.push(-a);	
}
int PostfixCalculator::getTopValue() const {
	return pile.top();
}

