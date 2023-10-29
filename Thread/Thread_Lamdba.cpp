#include<stdio.h>
#include<iostream>
#include<thread>
#include<windows.h>
int main(){
    []()->void{std::cout << "hello word" << std::endl;};
    std::thread t1([]()->void{std::cout << "hello word" << std::endl;});
    t1.join();
    for(int i=0;i<5;i++){
        std::cout << i << std::endl;
        Sleep(1000);
    }
    return 0;
}