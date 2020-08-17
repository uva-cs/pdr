#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = nullptr;
    right = nullptr;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
}
