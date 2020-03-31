# Alan Zheng (az4xfp)
# CS 2150, Lab Section 104
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
SANITIZER=-fsanitize=address -fno-omit-frame-pointer
OBJECTS=BinarySearchTree.o BinaryNode.o BSTPathTest.o
OUT=-o bst

bst: $(OBJECTS)
	$(CXX) $(DEBUG) $(SANITIZER) $(OBJECTS) $(OUT)

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o bst
