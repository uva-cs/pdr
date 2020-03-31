/**
    CS 2150, TreeCalc.h
    Purpose: header file for TreeCalc class

    @author Alan Zheng (az4xfp)
    @version 1.1 02/24/2020
*/
// TreeCalc.h: Tree Calculator class definition
// CS 2150: Lab 5
// You must submit ALL code to make your project build correctly


#ifndef TREECALC_H
#define TREECALC_H

#include <stack>

#include "TreeNode.h"
#include <stack>
using namespace std;

class TreeCalc {
public:
    TreeCalc();                     // Constructor
    ~TreeCalc();                    // Destructor

    void cleanTree(TreeNode* tree);  // Deletes tree/frees memory
    void readInput();               // Gets data from user
    void insert(const string& val); // Puts value in tree

    // print methods
    void printPrefix(TreeNode* tree) const;  // Prints data in prefix form
    void printInfix(TreeNode* tree) const;   // Prints data in infix form
    void printPostfix(TreeNode* tree) const; // Prints data in postfix form
    void printOutput() const;                // Prints in post, in, pre form
    int calculate();                         // Calls private calculate method

private:
    // declare a stack to hold your expression tree
    stack<TreeNode*> mystack;
    int calculate(TreeNode* ptr) const;		//Evaluates tree, returns value

};

#endif
