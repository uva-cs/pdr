/**
    CS 2150, ListNode.cpp
    Purpose: class file for ListNode class

    @author Alan Zheng (az4xfp)
    @version 1.1 01/25/2020
*/

#include "ListNode.h"

ListNode::ListNode() {
	next = NULL;
	previous = NULL;
}

ListNode::ListNode(int x) {
	value = x;
	next = NULL;
	previous = NULL;
}