/**
    CS 2150, TreeNode.cpp
    Purpose: class file for TreeNode class

    @author Alan Zheng (az4xfp)
    @version 1.1 02/24/2020
*/
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

#include "TreeNode.h"

// Default Constructor - left and right are NULL, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = NULL;
    right = NULL;
}
