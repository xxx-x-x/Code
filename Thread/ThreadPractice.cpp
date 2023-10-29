#include<stdio.h>
#include<thread>
#include<iostream>
#include<windows.h>
using namespace std;

void print(){
    for(int i=0;i<5;i++){
        std:cout<< i+1 << "..." << endl;
        Sleep(1000);
    }
}

void print2(){
    for(int i=0;i<5;i++){
        std:cout<< i+10 << "..." << endl;
        Sleep(1000);
    }
}
int main(){
    thread test(print);
    test.join();
    for(int i=0;i<5;i++){
        cout << i << endl;
    }
}