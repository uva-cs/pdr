/**
    CS 2150, hashTable.cpp
    Purpose: class file for hashTable

    @author Alan Zheng (az4xfp)
    @version 1.2 03/05/2020
*/

#include "hashTable.h"
#include <iostream>
#include <algorithm>
using namespace std;

hashTable::hashTable() {
    capacity = 1;
    size = 0;
    table.resize(capacity);
    for(unsigned int i = 0; i < sizeof(table)/sizeof(table[0]); i++){
        list<string> temp;
        table.push_back(temp);
    }
}

hashTable::~hashTable() {
}

void hashTable::insert(const string& x) {
    unsigned int h = hash(x);
	table.at(h%capacity).push_front(x);
    size++;
}

bool hashTable::contains(const string& x, unsigned int h){
    // unsigned int h = hash(x);
	list<string> lookup = table.at(h%capacity);
    // return (lookup.front() == x);
    list<string>::iterator end = lookup.end();
	return std::find(lookup.begin(),end,x) != end;
}

void hashTable::display() {
    for (int i=0; i<capacity; i++) {
        if (table.at(i).empty())
            continue;
        cout << i << ": ";
        for (string s : table.at(i))
            cout << s << " ";
        cout << endl;
    }
    cout << size << endl;
}

unsigned int hashTable::hash(const string& x, unsigned int hashVal) {
    // Jenkins hash
    // unsigned int hashVal = 0;

    // for(char const& c : x) {
    //     hashVal += c;
    //     hashVal += (hashVal << 10);
    //     hashVal ^= (hashVal >> 6);
    // }
    // return hashVal;

    // hashVal += (hashVal << 3);
    // hashVal ^= (hashVal >> 11);
    // hashVal += (hashVal << 15);
    // return hashVal;

    // fvn hash
    // unsigned int hash = 2166136261u; // humongous
    for (char const& c : x)
    {
        hashVal ^= c;
        hashVal *= 16777619;
    }
    return hashVal;

    //unsigned int hash = 7;
    // for (char const& c : x) {
    //     hashVal = hashVal*31 + c;
    // }
    // return hashVal;


    //what is this hash, works well with smaller dictionaries
    //minimum 25 collisions
    // unsigned int hashVal = 1;
    // for (char const& c : x) {
    //     hashVal *= ((c*37) % 128);
    //     hashVal = hashVal << 1;
    // }
    // return hashVal;
    
}

void hashTable::rehash(unsigned int n) {
    int count = 0;
    vector<list<string>> temp;
    temp.resize(n);
    for(unsigned int i = 0; i < capacity; i++){
        list<string> l = table.at(i);
        for(list<string>::const_iterator i = l.begin(); i != l.end(); ++i){
            string x = i->c_str();
            temp.at(hash(x)%n).push_front(x);
            count++;
        }
    }
    capacity = n;
    table = temp;
}


