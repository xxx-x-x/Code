#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

void max(int a,int b){
    if(a >b){
        cout << a;
    }else{
        cout << b;
    }
    cout << "max int";
}
void max(float a,float b){
    if(a>b){
        cout << a;
    }else{
        cout << b;
    }
    cout << "max float";
}
void max(char* str1,char* str2){
    if(strcmp(str1,str2)<0){
        cout << str2;
    }else{
        cout << str1;
    }
}
void max(vector<int> vec){
}
void max(vector<float> vec,int vec_siez){
}
void max(vector<string> vec,int vec_size){

}
int main(){
    float a = 1.0;
    float b = 2.0;
    max(a,b);
}