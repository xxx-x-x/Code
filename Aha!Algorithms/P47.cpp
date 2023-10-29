#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int *p = new int();
    *p = 10;

    int  *a = (int *)malloc(sizeof(int));
    *a = 10;
    cout << *p << " " << *a;
}