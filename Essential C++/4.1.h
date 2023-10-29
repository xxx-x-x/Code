#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Stack{
public:
    bool push(const string&);
    bool pop(string &elem);
    bool peek(string &elem);
    bool find(const string &elem);
    int count(const string &elem);

    bool empty();
    bool full();
private:
    vector<string> _stack;
};