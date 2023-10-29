#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

//自己理解的冒泡排序
void sort(vector<int>& a){
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i] > a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
//冒泡排序
void sort1(vector<int>& ivec){
    for(int i=1;i<ivec.size();i++){
        for(int j=0;j<ivec.size()-i;j++){
            if(ivec[j]>ivec[j+1]){
                int temp = ivec[j+1];
                ivec[j+1] = ivec[j];
                ivec[j] = temp;
            }
        }
    }
}
//
int main(){
    vector<int> ivec;
    int num1;
    cin >> num1;
    int n;
    for(int i=0;i<num1;i++){
        cin >> n;
        if(n<1 || n>1000){
            cerr << "ISBN不合理" << endl;
        }
        ivec.push_back(n);
    }
    sort(ivec);
    set<int> iset(ivec.begin(),ivec.end());
    set<int>::iterator it = iset.begin();
    set<int>::iterator ite = iset.end();
    cout << iset.size() << endl;
    for(;it!=ite;it++){
        cout << *it << " ";
    }
    return 0;
}