// Prime number generation code
//
// written by Aaron Bloomfield, 2014

#include <iostream>
#include "primenumber.h"
using namespace std;

int main() {
    int x;
    cout << "Enter number: ";
    cin >> x;
    cout << x << " is prime: " << checkprime(x) << endl;
    cout << "Next highest prime: " << getNextPrime(x) << endl;
}
