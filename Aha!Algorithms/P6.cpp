//初始化一个1000个int，输入一个数字，表示接下来要输入的个数，然后输入，排序
#include<stdio.h>
#include<iostream>
using namespace std;

#define sum 1000
int main(){
    int book[sum];
    for(int i= 0;i<sum;i++){
        book[i] = int();
    }
    int num;
    cin >> num;
    for(int ix=0;ix<num;ix++){
        int temp;
        cin >> temp;
        book[temp] ++ ;
    }
    for(int i=0;i<sum;i++){
        for(int j=0;j<book[i];j++){
            cout << i << " ";
        }
    }
    return 0; 
}