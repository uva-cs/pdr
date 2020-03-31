/**
    CS 2150, bitCounter.cpp
    Purpose: main file for bitCounter

    @author Alan Zheng (az4xfp)
    @version 1.1 02/11/2020
*/

#include <iostream>
using namespace std;

int counter(int n) {
	if (n==0)
		return 0;
	else
		return (n%2)+counter(n/2);
}

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "No command line input." << endl;
		return 0;
	}
	for (int i=2; i<argc; i++) {
		cout << argv[i] << endl;
		int n = stoi(argv[i]);
		int ones = counter(n);
		cout << argv[i] << " in binary has " << ones << " ones." << endl;
	}
	return 0;
}