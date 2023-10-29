#include<stdio.h>
#include<iostream>
using namespace std;
#define num 100
class Stack{
public:
    Stack(){
        for(int i=0;i<num;i++){
            _data[i] = int();
        }
        _top = -1;
    }
    int top(){
        return _top;
    }
    int pop(){
        return _data[_top--];
    }
    void push(int& elem){
        _data[++_top] = elem;
    }
    bool empty(){
        if(_top == -1){
            return true;
        }
        return false;
    }
    int size(){
        return _top+1;
    }
    bool find(int& elem){
        for(int i=0;i<_top;i++){
            if(_data[i] == elem){
                return true;
            }
        }
        return false;
    }
    int _data[num];
    int _top;
};

class Queue{
public:
    Queue(){
        for(int i=0;i<num;i++){
            _data[i] = int();
        }
        _head = 0;
        _tail = 0;
    }
    int pop(){
        return _data[_head++];
    }
    void push(int& elem){
        _data[_tail++] = elem;
    }
    int _data[num];
    int _head;
    int _tail;
};

int main(){

}