#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

inline void is_size_ok(int num){
    if(num>1024){
        cerr << "overflow" << endl; 
        exit(0);
    }
}
const vector<int>* Pentagonal(int num){
    //n(3n-1)/2
    is_size_ok(num);
    static vector<int> vnum;
    if(num<vnum.size()){
        //直接输出num之前的
        for(int i=0;i<num;i++){
            cout << vnum[i] << " " << endl;
        }
    }else{
        for(int i=vnum.size();i<num;i++){
            vnum.push_back((i+1) * (3* (i+1)-1)/2);
        }
    }
    return &vnum;
}
void showValue(const vector<int>* P ,int num){
    cout << (*P)[num-1] << endl;
}
int main(){
    const vector<int> *vec;
    int num = 5;
    vec = Pentagonal(num);
    showValue(vec,num);
}