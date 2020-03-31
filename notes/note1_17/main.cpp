//C++
//Lecture Notes 1/17/2020

#include <iostream>
#include "IntCell.h"
using namespace std;

int main() {
	IntCell m1; // calls the default constructor
	IntCell m2(37);
	cout << m1.getValue() << " " << m2.getValue() << endl;
	m1 = m2;
	m2.setValue(40);
	cout << m1.getValue() << " " << m2.getValue() << endl;

	return 0;
}
