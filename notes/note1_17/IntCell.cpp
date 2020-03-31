#include "IntCell.h"
using namespace std; // not really necessary

IntCell::IntCell(int initialValue) : storedValue(initialValue) {
	//equivalent to storedValue = initialValue in the body of the constructor
	//however, this syntax allows to set initial values for constant values
}

int IntCell::getValue() const {
	return storedValue;
}

void IntCell::setValue(int val) {
	storedValue = val;
}

int IntCell::max(int m) const {
	return (m>storedValue) ? m : storedValue;
}