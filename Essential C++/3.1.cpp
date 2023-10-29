#include<stdio.h>
#include<vector>
#include<iostream>
#include<fstream>
#include<iterator>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

template<typename T>
T* begin(vector<T> &vec){
    return vec.empty() ? 0 : &vec[0];
}
template<typename T>
T* end(vector<T> &vec){
    return vec.empty() ? 0 : &vec[vec.size()-1];
}
template<typename T>
T* find(T* first,T* last,const T& num){
    for(;first!=last;first++){
        if(*first == num){
            return first;
        }
    }
    return 0;                   
}

int main(){
    ifstream ifs("C:\\Users\\Administrator\\Desktop\\Code\\test.txt");
    ofstream ofs("C:\\Users\\Administrator\\Desktop\\Code\\test.txt",ios_base::app);
    if(!ifs || !ofs){
        cerr << "error !" << endl;
    }
    istream_iterator<string> is(ifs);
    istream_iterator<string> eof;
    ostream_iterator<string> os(ofs);
    map<string,int> words;
    vector<string> Vwords;
    copy(is,eof,back_inserter(Vwords));

    set<string> set1;
    set1.insert("a");
    set1.insert("an");
    set1.insert("or");
    set1.insert("the");
    set1.insert("and");
    set1.insert("but");

    vector<string>::iterator it = Vwords.begin();
    for(;it!=Vwords.end();it++){
        if(set1.count(*it))continue;
        words[*it]++;
    }
    map<string,int>::iterator mit = words.begin();
    for(;mit!=words.end();mit++){
        cout << mit->first << " : " << mit->second << endl;
    }
}