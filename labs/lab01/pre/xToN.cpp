// C++
// Alan Zheng, az4xfp
// 1/17/2020
// xToN.cpp

#include <iostream>
using namespace std;

int xton(int base, int power) {
	return (power == 0) ? 1 : base * xton(base, power-1);
}

int main() {
	int a, b;
	cout << "For the format a^b, input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	cout << a << "^" << b << "=" << xton(a,b) << endl;
	return 0;
}