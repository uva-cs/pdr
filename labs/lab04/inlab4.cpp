/**
    CS 2150, inlab4.cpp
    Purpose: main file for inlab4

    @author Alan Zheng (az4xfp)
    @version 1.1 02/11/2020
*/

#include <iostream>
using namespace std; 

int main() {
	// Representation in memory
	bool b = true;
	char c = 'c';
	int i = 0;
	double d = 1.0;
	int* p_i = new int(1);

	cout << "Boolean: " << b << endl;
	cout << "Character: " << c << endl;
	cout << "Integer: " << i << endl;
	cout << "Double: " << d <<endl;
	cout << "Integer Pointer: " << p_i << endl;

	// Primitive arrays in C++
	int IntArray[10]; //0x00007ffeefbffa30
	char CharArray[10]; //0x00007ffeefbffa26
	int IntArray2D[6][5]; //0x00007ffeefbff9a0
	char CharArray2D[6][5] = {'b'}; //0x00007ffeefbff980

	for (int i=0; i<sizeof(IntArray)/sizeof(*IntArray); i++)
		IntArray[i] = i;
	for (int i=0; i<sizeof(CharArray); i++) {
		if (i == sizeof(CharArray)-1)
			CharArray[i] = '\0';
		else
			CharArray[i] = 'b';
	}
	for (int i=0; i<sizeof(IntArray2D)/sizeof(IntArray2D[0]); i++)
		for (int j=0; j<sizeof(IntArray2D[0]); j++)
			IntArray2D[i][j] = i*j;
	for (int i=0; i<sizeof(CharArray2D)/sizeof(CharArray2D[0]); i++) {
		for (int j=0; j<sizeof(CharArray2D[0]); j++) {
			if (j == sizeof(CharArray2D[0])-1)
				CharArray2D[i][j] = '\0';
			else
				CharArray2D[i][j] = 'b';
		}
	}

	return 0;
}