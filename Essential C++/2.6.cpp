#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

template<typename T>
void max(T &a,T &b){
    cout << "aaa" << endl;
}

template<typename T>
void max(vector<T> vec,int vec_size){
}

int main(){
    float a = 1.0;
    float b = 2.0;
    max(a,b);
    return 0;
} 