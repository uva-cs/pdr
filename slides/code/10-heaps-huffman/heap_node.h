// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_NODE_H
#define HEAP_NODE_H

#include <vector>
using namespace std;

class heap_node {
public:
    heap_node();

private:
    int value;
    heap_node* left;
    heap_node* right;

    friend class binary_heap;
};

#endif
