#include<stdio.h>
#include<iostream>
using namespace std;

class A{
public:
void a();
};

//B 没有重写父类的 纯虚函数A ，导致B 继承了 纯虚函数，从而使B 变成了 抽象类，无法实例化对象
class B{
public:
    B ( A a){
        _a = a;
    }
    A _a;
};

int main(){
    int a ;
    a = int();
    cout << a << endl;
    return 0;
}