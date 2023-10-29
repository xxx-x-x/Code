#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int askName1(){//1.5.1
    string name;
    cout << "input" <<endl;
    cin >> name;
    if(name.size()<2){
        cerr<< "restart" << endl;
    }
    cout << "your name is " + name <<endl;
    return 0;
}

int askName2(){//1.5.2
    char name[100];
    cout << " input" << endl;
    cin >> name;
    if(strlen(name)<2){
        cerr << "restart" << endl;
    }
    return 0;
}

int main(){
    askName1();
    return 0;
}