// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "binary_heap.h"
using namespace std;

// default constructor
binary_heap::binary_heap() : heap_size(0) {
    heap.push_back(0);
}

// builds a heap from an unsorted vector
binary_heap::binary_heap(vector<int> vec) : heap_size(vec.size()) {
    heap = vec;
    heap.push_back(heap[0]);
    heap[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
binary_heap::~binary_heap() {
}

void binary_heap::insert(int x) {
    // a vector push_back will resize as necessary
    heap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void binary_heap::percolateUp(int hole) {
    // get the value just inserted
    int x = heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < heap[hole/2]); hole /= 2 )
        heap[hole] = heap[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    heap[hole] = x;
}

int binary_heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    int ret = heap[1];
    // move the last inserted position into the root
    heap[1] = heap[heap_size--];
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void binary_heap::percolateDown(int hole) {
    // get the value to percolate down
    int x = heap[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (heap[child+1] < heap[child]) )
            child++;
        // if the child is greater than the node...
        if ( x > heap[child] ) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

int binary_heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return heap[1];
}

unsigned int binary_heap::size() {
    return heap_size;
}

void binary_heap::makeEmpty() {
    heap_size = 0;
    heap.resize(1);
}

bool binary_heap::isEmpty() {
    return heap_size == 0;
}

heap_node* binary_heap::createTree() {
  // Create all heap nodes and store them in an array
  heap_node* nodes[heap_size+1]; // array containing all heap nodes
  nodes[0] = NULL; // ignore the zero index
  for (int i = 1; i <= heap_size; i++) {
    heap_node* n = new heap_node;
    n->value = heap[i];
    nodes[i] = n;
  }
  cout << endl;

  // Create the tree
  // For every node x, we want to insert its left and right child
  for (int i = 1; i <= heap_size; i++) {
    heap_node* current = nodes[i];
    int leftChildIndex = 2*i;
    int rightChildIndex = 2*i + 1;

    // If the index of the left child is larger than the number of
    // elements in the heap, it means that the current node doesn't
    // have a left child.
    if (leftChildIndex >= heap_size+1)
      current->left = NULL;
    else
      current->left = nodes[leftChildIndex];
    
    // If the index of the right child is larger than the number of
    // elements in the heap, it means that the current node doesn't
    // have a right child.
    if (rightChildIndex >= heap_size+1)
      current->right = NULL;
    else
      current->right = nodes[rightChildIndex];
  }

  return nodes[1]; // return the root node of the tree
}

void binary_heap::print() {
    cout << "(" << heap[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << heap[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}
