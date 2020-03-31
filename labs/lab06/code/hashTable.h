/**
    CS 2150, hashTable.h
    Purpose: header file for hashTable

    @author Alan Zheng (az4xfp)
    @version 1.2 03/05/2020
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <list>
#include <vector>
using namespace std;

class hashTable {
public:
    hashTable();
    ~hashTable();
    void insert(const string& x); 
    bool contains(const string& x, unsigned int h);
    void display();
    unsigned int hash(const string& x, unsigned int hash=2166136261u);
    void rehash(unsigned int n);
private:
    vector<list<string>> table;
    int capacity;
    int size;
};

#endif