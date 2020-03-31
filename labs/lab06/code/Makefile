# Alan Zheng (az4xfp)
# CS 2150, Lab Section 104
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2 #-Wall  # Enable all warnings
SANITIZER=#-fsanitize=address -fno-omit-frame-pointer
DEBUG=#-g
OBJECTS=wordPuzzle.o hashTable.o timer.o

a.out: $(OBJECTS)
	$(CXX) $(SANITIZER) $(DEBUG) $(OBJECTS)

hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o a.out

