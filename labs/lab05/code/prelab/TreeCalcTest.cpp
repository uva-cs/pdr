/**
    CS 2150, TreeCalcTest.cpp
    Purpose: main file to test TreeCalc

    @author Alan Zheng (az4xfp)
    @version 1.1 02/24/2020
*/

// TreeCalcTest.cpp
// CS 2150: Tree calculator test program
// Your code MUST work with an UNMODIFIED version of this test program
// We will be using this program to test your implementations

#include <iostream>
#include "TreeCalc.h"

using namespace std;

int main() {
    TreeCalc tester;
    // read expression input from the user
    tester.readInput();
    // print out the output in postorder, in order, preorder forms
    tester.printOutput();
    // calculate the result of the expression tree
    cout << "The result of the expression tree is " << tester.calculate() << endl;
    return 0;
}
