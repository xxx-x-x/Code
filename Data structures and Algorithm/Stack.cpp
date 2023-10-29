#include<stack>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    for(int i=0;i<s1.size();i++){
        cout<< s1.top() << " ";
    }
    return 0;
}