#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = nullptr;
    right = nullptr;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
}
