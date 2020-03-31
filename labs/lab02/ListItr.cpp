/**
    CS 2150, ListItr.cpp
    Purpose: class file for ListItr class

    @author Alan Zheng (az4xfp)
    @version 1.1 01/25/2020
*/

#include <iostream>
#include "ListItr.h"
using namespace std;

ListItr::ListItr() {
	current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
    current = theNode;
}

// Returns true if the iterator is currently pointing past the end position
// in the list (i.e., it's pointing to the dummy tail), else false
bool ListItr::isPastEnd() const {
    return current->next == NULL;
}

// Returns true if the iterator is currently pointing past (before) the first position
// in list (i.e., it's pointing to the dummy head), else false
bool ListItr::isPastBeginning() const {
    return current->previous == NULL;
}

// Advances `current` to the next position in the list (unless already past the end of the list)
void ListItr::moveForward() {
	if (isPastEnd()) {
		cout << "Reached the end of the list." << endl;
		return;
	}
    current = current->next;
}

// Moves `current` back to the previous position in the list (unless already past the beginning of the list)
void ListItr::moveBackward() {
	if (isPastBeginning()) {
		cout << "Reached the beginning of the list." << endl;
		return;
	}
    current = current->previous;
}

// Returns the value of the item in the current position of the list
int ListItr::retrieve() const {
    return current->value;
}