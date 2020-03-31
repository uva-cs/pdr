/**
    CS 2150, AVLNode.h
    Purpose: header file for AVLNode

    @author Alan Zheng (az4xfp)
    @version 1.1 02/26/2020
*/

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
    AVLNode();
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    friend class AVLTree;
};

#endif