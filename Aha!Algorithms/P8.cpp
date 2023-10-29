//尝试一下冒泡排序
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int a[5] = {5,10,21,12,3};
    //i表示几趟，直接用相同数字表示更直观，5个排序，是4趟，
    //第1 趟比较 5个数字，下标从0到4，每个j和下一个j+1比较，所以j 是0到3，即5-i；
    for(int i=1;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(a[j]<a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        cout << a[i] << ' ' ;
    }
} 