#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

#define num 100

template<typename elemType>
class Stack{
public:
    Stack(){
        for(int i=0;i<num;i++){
            _a[i] = elemType();
        }
        _top = -1;//下标默认从零开始
    }
    void push(const elemType& elem){
        _a[++_top] = elem;
    }
    elemType& pop(){
        return _a[_top--];
    }
    void print(){
        while(_top!=-1){
            cout << _a[_top--] << " ";
        }
        cout << endl;
    }
    int top(){
        return _top;
    }
private:
    elemType _a[num];
    int _top;
};

int main(){
    Stack<char> s1;
    string str;
    cin >> str;
    int mid;
    if(str.length()%2 == 0){
        mid = str.length()/2;
    }else{
        mid = str.length()/2+1;
    }

    for(int i=0;i<mid;i++){
        s1.push(str[i]);
    }
    if(mid == str.length()/2+1){
        s1.pop();//中点我不要了
    }
    for(int i=mid;i<str.length();i++){

        if(s1.pop() != str[i]){
            cerr << s1.pop() << "!="<< str[i] <<endl;
            break;
        }
    }
    if(s1.top() == -1){
        printf("这是一个回文\n");
    }else{
        printf("这个不是回文\n");
    }
    return  0;
}