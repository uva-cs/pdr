/**
    CS 2150, AVLNode.cpp
    Purpose: main file for AVLTree testing

    @author Alan Zheng (az4xfp)
    @version 1.1 02/26/2020
*/

#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
    AVLTree avl;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            avl.insert(word);
            avl.printTree();
        } else if (instr == "R") {
            avl.remove(word);
        } else if (instr == "L") {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }
    }
    cout << "AVL numNodes: " << avl.numNodes() << endl;
    avl.~AVLTree();
}