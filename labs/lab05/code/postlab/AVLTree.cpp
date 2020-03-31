/**
    CS 2150, AVLTree.cpp
    Purpose: class file for AVLTree

    @author Alan Zheng (az4xfp)
    @version 1.1 02/26/2020
*/
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    insert(x, root);
}

void AVLTree::insert(const string& x, AVLNode* &curr) {
    if (curr == NULL) {
        curr = new AVLNode();
        curr->value = x;
    }
    else if (x < curr->value)
        insert(x, curr->left);
    else if (x > curr->value)
        insert(x, curr->right);
    else
        return;
    curr->height = 1 + max(height(curr->left), height(curr->right));
    int val = height(curr->right)-height(curr->left);
    if (abs(val)>1) {
        balance(curr);
    }
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    string ret = "";
    AVLNode* curr = root;
    if (curr == NULL)
        return "";
    while (curr->value != x) {
        ret += curr->value;
        ret += " ";
        if (x<curr->value)
            curr = curr->left;
        else if (x>curr->value)
            curr = curr->right;
        if (curr == NULL)
            return "";
    }
    ret += curr->value;
    return ret;
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    AVLNode* curr = root;
    while (curr != NULL and curr->value != x) {
        if (x<curr->value)
            curr = curr->left;
        else if (x>curr->value)
            curr = curr->right;
    }
    if (curr == NULL)
        return false;
    return true;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return numNodes(root);
}
int AVLTree::numNodes(AVLNode* curr) const {
    if (curr == NULL)
        return 0;
    if (curr->left == NULL and curr->right == NULL)
        return 1;
    return 1 + numNodes(curr->left) + numNodes(curr->right);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    int factor = height(n->right)-height(n->left);
    if (factor == 2) {
        int r;
        if (n->right == NULL)
            r = -1;
        else
            r = height(n->right->right)-height(n->right->left);
        if (r<0)
            rotateRight(n->right);
        rotateLeft(n);
    }
    else if (factor == -2) {
        int l;
        if (n->left == NULL)
            l = -1;
        else
            l = height(n->left->right)-height(n->left->left);
        if (l>0)
            rotateLeft(n->left);
        rotateRight(n);
        // how to update parent child?
    }
    /*if balance factor of node is 2 we will need to rotate left:
        first, see if we should also rotate right (i.e., do a double rotation)
        if balance factor of right child is negative:
            rotate right on the right child
        endif
        rotate left on node
    else if balance factor of node is -2 we will need to rotate right:
        first, see if we should also rotate left (i.e., double rotation)
        if balance factor of left is positive:
            rotate left on the left child
        endif
        rotate right on node
    endif*/
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    AVLNode* right = n->right;  
    AVLNode* t2 = right->left;
    right->left = n; 
    n->right = t2;
    n->height = max(height(n->left), height(n->right)) + 1;  
    right->height = max(height(right->left), height(right->right)) + 1;
    n = right;
    return right;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    AVLNode* left = n->left;  
    AVLNode* t2 = left->right;
    left->right = n;  
    n->left = t2;
    n->height = max(height(n->left), height(n->right)) + 1;  
    left->height = max(height(left->left), height(left->right)) + 1;
    n = left;
    return left; 
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
