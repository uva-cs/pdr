# Alan Zheng (az4xfp), CS 2150
#!/bin/bash
echo "Enter your dictionary file first, then the grid file:"
read dictfile
read gridfile
RUNNING_TIME1=`./a.out $dictfile $gridfile | tail -1`
echo 'one'
RUNNING_TIME2=`./a.out $dictfile $gridfile | tail -1`
echo 'two'
RUNNING_TIME3=`./a.out $dictfile $gridfile | tail -1`
echo 'three'
RUNNING_TIME4=`./a.out $dictfile $gridfile | tail -1`
echo 'four'
RUNNING_TIME5=`./a.out $dictfile $gridfile | tail -1`
echo 'five'
average=$(((RUNNING_TIME1+RUNNING_TIME2+RUNNING_TIME3+RUNNING_TIME4+RUNNING_TIME5)/5))

echo ${average} 'milliseconds on average over 5 runs.'