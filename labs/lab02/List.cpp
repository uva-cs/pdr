/**
    CS 2150, List.cpp
    Purpose: class file for List class

    @author Alan Zheng (az4xfp)
    @version 1.1 01/25/2020
*/

#include <iostream>
#include "List.h"
using namespace std;

List::List() {
	head = new ListNode();
    tail = new ListNode();
	head->next = tail;
    tail->previous = head;
    count = 0;
}

List::List(const List& source) {
	head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
List::~List() {
	makeEmpty(); 
    delete head;
    delete tail;
}

List& List::operator=(const List& source) {
	if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
	return size() <= 0;
}

// Removes (deletes) all items except the dummy head/tail.
// The list should be a working empty list after this.
void List::makeEmpty() {
	ListItr* temp = new ListItr(first());
	while (!temp->isPastEnd()) {
		temp->moveForward();
		delete temp->current->previous;
	}
	delete temp;
	head->next = tail;
	tail->previous = head;
	count = 0;
}

// Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List::first() {
	ListItr* ret = new ListItr(head->next);
	return *ret;
}

// Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List::last() {
	ListItr* ret = new ListItr(tail->previous);
	return *ret;
}

// Inserts x after current iterator position
void List::insertAfter(int x, ListItr position) {
	if (position.isPastEnd())
		insertAtTail(x);
	else {
		ListNode* n = new ListNode(x);
		n->previous = position.current;
		n->next = position.current->next;
		position.current->next = n;
		n->next->previous = n;
		count++;
	}
}

// Inserts x before current iterator position
void List::insertBefore(int x, ListItr position) {
	if (position.isPastBeginning()){
		insertAtHead(x);
	}
	else {
		ListNode* n = new ListNode(x);
		n->next = position.current;
		n->previous = position.current->previous;
		position.current->previous = n;
		n->previous->next = n;
		count++;
	}
}

// Inserts x at tail of list
void List::insertAtTail(int x) {
	ListNode* n = new ListNode(x);
	n->next = tail;
	n->previous = tail->previous;
	tail->previous->next = n;
	tail->previous = n;
	count++;
}

// Inserts x at head of list
void List::insertAtHead(int x) {
	ListNode* n = new ListNode(x);
	n->previous = head;
	n->next = head->next;
	head->next->previous = n;
	head->next = n;
	count++;
}

// Returns an iterator that points to the first occurrence of x.
// When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
// This makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List::find(int x) {
	ListItr* ret = new ListItr(first());
	while (ret->retrieve() != x and !ret->isPastEnd())
		ret->moveForward();
	return *ret;
}

// Removes the first occurrence of x
void List::remove(int x) {
	ListItr* rem = new ListItr(find(x));
	if (!rem->isPastEnd()) {
		rem->current->previous->next = rem->current->next;
		rem->current->next->previous = rem->current->previous;
		count--;
		delete rem;
	}
}

// Returns the number of elements in the list
int List::size() const {
	return count;
}

void printList(List& source, bool forward) {
	ListItr itr = (forward) ? source.first() : source.last();
	if (forward) {
		while (!itr.isPastEnd()) {
			cout << itr.retrieve() << " ";
			itr.moveForward();
		}
	}
	else {
		while (!itr.isPastBeginning()) {
			cout << itr.retrieve() << " ";
			itr.moveBackward();
		}
	}
	cout << endl;
}