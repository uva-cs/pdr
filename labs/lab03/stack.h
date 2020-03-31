/**
    CS 2150, stack.h
    Purpose: header file for MyStack class

    @author Alan Zheng (az4xfp)
    @version 1.1 02/04/2020
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
using namespace std;

class List;

class MyStack {
public:
	MyStack();
	~MyStack();
    void push(int x);
    void pop();
    int top() const;
    bool empty() const;

private:
    List *list;
};

#endif