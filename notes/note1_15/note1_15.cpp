// C++
// Lecture Notes: 1/15/2020

/*Preprocessing. Compiler inserts the contents of the 
file in the place where the #include statement appears.*/
#include <iostream>

/*Similar to Java's import. Uses a namespace, which is somewhat
similar to a Java package. Allows the programmer to not have to 
type the full namespace name each time.*/
using namespace std;

int main() {
	//std::endl is new line
	cout << "Hello World" << endl;

	//I/O
	int x;
	cout << "Enter a value for x: ";
	cin >> x;
	cout <<"x is " << x;

	//For if statements, conditions can be either int or bool
	//Loops, same as Java: while, for, dowhile, break, continue
	//Functions: methods that are members of a class
	//C++ is single path compiler

	return 0;
}