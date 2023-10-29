#include<stdio.h>
#include<thread>
#include<iostream>

int n = 0;

void increase_number(){
    for(int i=0;i<10000;i++){
        n++;
    }
}

int main(){
    for(int i=0;i<10;i++){
        std::thread(increase_number);
    }
    std::cout<<n<<std::endl;
}