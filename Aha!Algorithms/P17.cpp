#include<stdio.h>
#include<iostream>
using namespace std;

int a[10] = {6,1,2,7,9,3,4,5,10,8};

void QuickSort(int left,int right){
    int temp; // 用这个来保存基数
    int i,j;//创建两个标兵
    i = left;
    j = right; 
    if(left>right){
        return ;//因为这是错误的
    }
    temp = a[left];// 最左边默认是基数。
    while (i!=j)
    {
        //从右往左找
        while (a[j]>=temp&&i<j)
        {
            j--;
        }
        while (a[i]<=temp&&i<j)
        {
            i++;
        }
        if(i<j){
            int t;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;
    QuickSort(left,i-1);
    QuickSort(i+1,right);
}

int main(){
    QuickSort(0,9);
    for(int i=0;i<10;i++){
        cout << a[i] << " ";
    }
    return 0;
}