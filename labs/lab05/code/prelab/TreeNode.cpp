// Insert your header information here
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

#include "TreeNode.h"

// Default Constructor - left and right are nullptr, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = nullptr;
    right = nullptr;
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = nullptr;
    right = nullptr;
}
