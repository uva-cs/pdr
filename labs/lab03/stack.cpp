/**
    CS 2150, stack.cpp
    Purpose: class file for MyStack class

    @author Alan Zheng (az4xfp)
    @version 1.1 02/04/2020
*/

#include <iostream>
#include "stack.h"
using namespace std;

MyStack::MyStack() {
	list = new List();
}

MyStack::~MyStack() {
	list->makeEmpty();
	delete list;
}

void MyStack::push(int x) {
	list->insertAtTail(x);
}

void MyStack::pop() {
	list->removeAtTail();
}

int MyStack::top() const{
	ListItr* temp = new ListItr(list->last());
	int ret = temp->retrieve();
	delete temp;
	return ret;
}

bool MyStack::empty() const{
	return list->isEmpty();
}