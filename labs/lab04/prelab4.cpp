/**
    CS 2150, prelab4.cpp
    Purpose: main file for prelab4

    @author Alan Zheng (az4xfp)
    @version 1.1 02/07/2020
*/

#include <iostream>
#include <limits.h>
using namespace std;

void sizeOfTest() {
	cout << "These are the sizes of each data type:" << endl;
	cout << "Integer: " << sizeof(int) << endl;
	cout << "Unsigned Integer: " << sizeof(unsigned int) << endl;
	cout << "Float: " << sizeof(float) << endl;
	cout << "Double: " << sizeof(double) << endl;
	cout << "Character: " << sizeof(char) << endl;
	cout << "Boolean: " << sizeof(bool) << endl;
	cout << "Integer*: " << sizeof(int*) << endl;
	cout << "Char*: " << sizeof(char*) << endl;
	cout << "Double*: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int x) {
	string s("");
	for (int i = 0; i < 32; ++i) {
		if (i %4 == 0)
			s = s.insert(0, " ");
		s = s.insert(0, x%2==1 ? "1" : "0");
		x = x>>1;
	}
	cout << s << endl;
}

void overflow() {
	unsigned int max = UINT_MAX;
	cout << max << endl;
	max += 1;
	cout << max << endl;
	cout << "When you add one to the maximum value of an unsigned integer, the program does not halt and the value of the unsigned integer becomes zero. This is because when the number exceeds its limit, it actually wraps back around to the minimum value of that data type. For unsigned integers, that value is zero." << endl;
	
}

int main() {
	sizeOfTest();
	cout << "Enter a number to convert to binary: ";
	int x;
	cin >> x;
	outputBinary(x);
	overflow();
	return 0;
}