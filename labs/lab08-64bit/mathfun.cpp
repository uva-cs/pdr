/**
    CS 2150, mathfun.cpp
    Purpose: main file to test mathlib.s

    @author Alan Zheng (az4xfp)
    @version 1.2 03/30/2020
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);

int main () {

    // delcare the local variables
    long  a, b, p;

    // what are our numbers
    cout << "Please enter the first number:  ";
    cin >> a;
    cout << "Please enter the second number:  ";
    cin >> b;

    // sanity check the array size
    if (a <= 0 or b <= 0) {
        cerr << "Numbers must be positive.\n";
        return 1;
    }
    // call the function
    p = product(a, b);
    cout << "The product of the numbers is " << p << endl;
    return 0;
}
