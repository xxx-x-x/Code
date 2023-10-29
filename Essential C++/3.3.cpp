#include<map>
#include<set>
#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;

void display(map<string,int> words);
int main(){
    string str[6] = {"one","two","three","four","five","six"};
    map<string,int> words;
    for(int i=0;i<sizeof(str)/sizeof(string);i++){
        words[str[i]]++;
    }
    string str1;
    cin >> str1;
    map<string,int>::iterator it;
    it = words.find(str1);
    cout << it->first << " : " << it->second << endl;
}

void display(map<string,int> words){
    map<string,int>:: iterator it = words.begin();
    for(;it!=words.end();it++){
        cout << it->first << " + " << it-> second << endl;
    }
}