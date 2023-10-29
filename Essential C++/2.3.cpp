#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void Pentagonal(vector<int> &vnum,int num){
    //n(3n-1)/2
    if(num > 1024){
        cerr << "overflow" << endl;
    }
    for (int i=0;i<num;i++){
        vnum.push_back((i+1) * (3* (i+1)-1)/2);
    }
}

void display(vector<int> vnum,string str = "int"){
    cout << "int number" << endl;
    for(int i=0;i<vnum.size();i++){
        cout << vnum[i] << " ";
    }
}

int main(){
    vector<int> vec;
    int num = 5;
    Pentagonal(vec,num);
    display(vec);
}