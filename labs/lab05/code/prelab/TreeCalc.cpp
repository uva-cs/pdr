/**
    CS 2150, TreeCalc.cpp
    Purpose: class file for TreeCalc class

    @author Alan Zheng (az4xfp)
    @version 1.1 02/24/2020
*/
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    cleanTree(mystack.top());
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if (ptr!= NULL) {
        cleanTree(ptr->left);
        cleanTree(ptr->right);
        delete ptr;
    }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode* node = new TreeNode(val);
    if (val == "+" or val == "-" or val == "*" or val == "/") {
        TreeNode* x = mystack.top();
        mystack.pop();
        TreeNode* y = mystack.top();
        mystack.pop();
        node->left = y;
        node->right = x;
    }
    mystack.push(node);
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
    string val = ptr->value;
    if (val == "+" or val == "-" or val == "*" or val == "/") {
        cout << val << " ";
        printPrefix(ptr->left);
        printPrefix(ptr->right);
    }
    else
        cout << val << " ";
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    string val = ptr->value;
    if (val == "+" or val == "-" or val == "*" or val == "/") {
        cout << "( ";
        printInfix(ptr->left);
        cout << val << " ";
        printInfix(ptr->right);
        cout << ") ";
    }
    else
        cout << val << " ";
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    string val = ptr->value;
    if (ptr->left != NULL and ptr->right != NULL) {
        printPostfix(ptr->left);
        printPostfix(ptr->right);
        cout << val << " ";
    }
    else
        cout << val << " ";
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
    if (ptr->left == NULL and ptr->right == NULL)
        return stoi(ptr->value);
    int v1 = calculate(ptr->left);
    int v2 = calculate(ptr->right);
    string operation = ptr->value;
    if (operation == "+") {
        return v1+v2;
    }
    else if (operation == "-") {
        return v1-v2;
    }
    else if (operation == "*") {
        return v1*v2;
    } 
    else if (operation == "/") {
        return v1/v2;
    }
    return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(mystack.top());
    return i;
}
