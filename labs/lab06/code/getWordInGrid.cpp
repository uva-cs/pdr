/** This file defines and demonstrates two necessary components for
 * the hash table lab for CS 2150.  The first is the use of the
 * getWordInGrid() function, which is used for retrieving a word in a
 * grid of letters in one of the cardinal 8 directions (north,
 * south-east, etc).  The second is the use of file streams to read in
 * input from a file, specifically one formatted as per the lab 6
 * guidelines.
 *
 * Written by Aaron Bloomfield, 2009
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "getWordInGrid.h"
using namespace std;

/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */
int main() {
    // to hold the number of rows and cols in the input file
    int rows, cols;
    // attempt to read in the file
    bool result = readInGrid ("5x8.grid.txt", rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
    // Get a word (of length 10), starting at position (2,2) in the
    // array, in each of the 8 directions
    cout << endl;
    for ( int i = 0; i < 8; i++ )
        cout << i << ": " << getWordInGrid(2,2,i,10,rows,cols) << endl;
    // All done!
    return 0;
}
