#include<stdio.h>
#include<iostream>
#include<thread>

void printf(int a){
    a++;
    std::cout << a << std::endl;
    std::cout << "child thread" << std::endl;
}
int main(){
    int a = 0;
    std::thread t1(printf,std::ref(a));
    t1.join();
    std::cout << "main thread" << std::endl;
    return 0;
}