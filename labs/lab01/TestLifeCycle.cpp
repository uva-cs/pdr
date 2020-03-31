/**
    CS 2150, TestLifeCycle.cpp
    Purpose: main file to test LifeCycle class

    @author Alan Zheng (az4xfp)
    @version 1.1 01/21/2020
*/

#include <iostream>
#include <string>
#include "LifeCycle.h"
using namespace std;

// Static variables
int MyObject::numObjs = 0;  // static member for all objects in class
static MyObject staticObj("I'm static, outside of main");

int main () {
    cout << "--PART 1: Start of main--" << endl;
    cout << "--Defining o1, o2(\"Bob\")--" << endl;
    MyObject o1, o2("Bob");

    cout << "--Defining o3(o2)--" << endl;
    MyObject o3(o2);

    cout << "--Defining array of 3 objects--" << endl;
    MyObject array[3];

    cout << endl;

    cout << "--PART 2: call function using call-by-value, return int--" << endl;
    cmpMyObj(o1, o3);

    cout << "--call function using call-by-value, return MyObject--" << endl;
    getMaxMyObj(o1, o3);

    cout << endl;

    cout << "--PART 3:  o1: " << o1 << endl;
    {
        cout << "  --entering new block, define new o1(Sally)--" << endl;
        MyObject o1("Sally");
        o1.setName("Sally");
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;

        cout << "  --call swap function using call-by-reference--" << endl;
        swapMyObj(o1, o2);

        cout << "  --were their values swapped?--" << endl;
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;
        cout << "  --leaving new block--" << endl;
    }
    cout << "o1: " << o1 << endl;

    cout << endl;

    cout << "--PART 4: Define reference var: { MyObject& oref=o1; } --" << endl;
    {
        MyObject& oref=o1;
    }
    cout << "-- was anything constructed/destructed?--" << endl;

    cout << endl;

    cout << "--PART 5: new and delete--" << endl;
    cout << "--use new to create one object, then array of 2 objects--" << endl;
    MyObject *op1 = new MyObject, *op2 = new MyObject[2];

    cout << "--use delete to remove that one object--" << endl;
    delete op1;

    cout << "--use delete [] to remove that array of 2 objects --" << endl;
    delete[] op2;

    cout << endl;

    cout << "--LAST PART:  End of main--" << endl;
    return 0;
}

// Define the functions we declared earlier
int cmpMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if (name1 == name2) {
        return 0;
    } else if (name1 < name2) {
        return -1;
    } else {
        return 1;
    }
}

MyObject getMaxMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if (name1 >= name2) {
        return o1;
    } else {
        return o2;
    }
}

void swapMyObj(MyObject& o1, MyObject& o2) {
    MyObject tmp(o1);
    o1.setName(o2.getName());
    o2.setName(tmp.getName());
}