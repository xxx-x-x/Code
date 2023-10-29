#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string str;
    vector<string> vec;
    ifstream infile("C:\\Users\\Administrator\\Desktop\\Code\\1.7.txt");
    ofstream outfile("C:\\Users\\Administrator\\Desktop\\Code\\1.7.txt",ios_base::app);
    if(!infile || !outfile){
        cerr << "error" << endl; 
    }else{
        while(infile>>str){
            vec.push_back(str);
        }
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
        outfile << vec[i];
    }
    return 0;
}