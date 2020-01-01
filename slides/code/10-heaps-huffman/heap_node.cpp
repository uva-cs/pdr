// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "binary_heap.h"
#include "heap_node.h"
using namespace std;

// default constructor
heap_node::heap_node() {
  this->value = 0;
  this->left = NULL;
  this->right = NULL;
}
