#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int str_size = 4;
    string str[str_size] = {"one","two","three","four"};
    int num;
    cin >>num;
    cout << str[num%4];
}