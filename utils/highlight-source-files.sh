#!/bin/bash

# sed operates differently on different systems
if [ x`uname` == x"Darwin" ]; then
    echo this script cannot be run on Darwin
    exit
fi

# take every path in the repo ending in .c, .cpp, .h, or Makefile, ignoring those under book
for infile in `find . -type f \( -name '*.c' -or -name '*.cpp' -or\
                                 -name '*.h' -or -name 'Makefile' \) | grep -v 'book'`; do
    source-highlight --doc $infile --title `basename $infile` --out-format html5 --quiet --gen-version
    $SED s/"<html>"/"<html lang='en'>"/ $infile.html
    $SED s/"<pre>"/"<main><pre>"/ $infile.html
    $SED s_"</pre>"_"</pre></main>"_ $infile.html
done

# for Assembly files, treat them as Assembly and not S
for infile in `find . -type f -name '*.s' | grep -v 'book'`; do
    source-highlight --doc $infile --title `basename $infile` --out-format html5 --quiet --gen-version --lang-def 'asm.lang'
    $SED s/"<html>"/"<html lang='en'>"/ $infile.html
    $SED s/"<pre>"/"<main><pre>"/ $infile.html
    $SED s_"</pre>"_"</pre></main>"_ $infile.html
done
