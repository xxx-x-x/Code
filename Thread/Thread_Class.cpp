#include<stdio.h>
#include<iostream>
#include<thread>

class Cthread{
public:
    void operator()(){
        std::cout << "thread 1" << std::endl;
    }
};
//函数对象，最后其实就是 Cthread() 函数，这个函数有一个输出功能，Cthread还是函数名，本质和普通的还是一样的
int main(){
    Cthread c1;
    std::thread t1(c1);
    t1.join();
    
    std::thread t2((Cthread()));
    t2.join();
}