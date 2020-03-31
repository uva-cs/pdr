# Alan Zheng (az4xfp)
# CS 2150, Lab Section 104
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
SANITIZER=-fsanitize=address -fno-omit-frame-pointer
DEBUG=-g
OBJECTS=AVLNode.o AVLPathTest.o AVLTree.o
OUT=-o a.out

a.out: $(OBJECTS)
	$(CXX) $(SANITIZER) $(DEBUG) $(OBJECTS) $(OUT)

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out

