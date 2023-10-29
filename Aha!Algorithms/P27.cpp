#include<stdio.h>
#include<iostream>
using namespace std;

struct Queue
{
    //必须给够100个，不然数组下标越界了，但是编译器不会报错。
    int a[100];
    int head;
    int tail;
};

int main(){
    struct Queue Q1;
    Q1.head = 0;
    Q1.tail = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> Q1.a[Q1.tail];
        Q1.tail ++;
    }
    while (Q1.head != Q1.tail)
    {
        cout << Q1.a[Q1.head];
        Q1.head++;
        Q1.a[Q1.tail] = Q1.a[Q1.head];
        Q1.tail++;
        Q1.head++;
    }
}