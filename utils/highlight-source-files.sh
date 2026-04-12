#!/bin/bash

# sed operates differently on different systems
if [ x`uname` == x"Darwin" ]; then
    echo this script cannot be run on Darwin
    exit
fi

# take every path in the repo ending in .c, .cpp, .h, or Makefile, ignoring those under book
for infile in `find . -type f \( -name '*.c' -or -name '*.cpp' -or\
                                 -name '*.h' -or -name 'Makefile' \) | grep -v 'book'`; do
    custom-source-highlight.sh $infile
done

# for Assembly files, treat them as Assembly and not S
for infile in `find . -type f -name '*.s' | grep -v 'book'`; do
    custom-source-highlight.sh $infile
done
