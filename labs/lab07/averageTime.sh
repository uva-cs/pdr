# Alan Zheng (az4xfp), CS 2150
#!/bin/bash

while true; do
    n=5
    echo "Enter 'quit' to quit"
    echo "enter the exponent for counter.cpp"
    read input
    if [ $input == "quit" ]; then
      exit 0
    fi
    sum=0
    for (( i=0; i<=n; i++ )); do
        echo "Running iteration ${i}:"
        time=`./a.out ${input}`
        sum=`expr $sum + $time`
        echo "time taken: ${time} milliseconds"
    done
    echo "Average time: "`expr $sum / 5` milliseconds
done