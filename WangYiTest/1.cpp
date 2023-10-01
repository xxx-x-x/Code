#include <stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;
int main(){
    vector<char> l1; 
    string s1,s2;
    cin >> s1;
    cin >> s2;
    for(int i =0;i<s1.size();i++)
    {
        if(s1[i]!=',')
        {
            l1.push_back(s1[i]);
        }
    }
    for(int i=0;i<s1.size();i++)
    {
        if(s2[i]!=',')
        {
            l1.push_back(s2[i]);
        }
    }
    sort(l1.rbegin(),l1.rend());
    for(int i=0;i<l1.size()-1;i++)sort
    {
        cout << l1[i]<<',';
    }
    cout << l1[l1.size()-1];

}