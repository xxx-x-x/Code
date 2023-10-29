#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

bool less_than(int v1,int v2){
    return v1<v2 ? true : false;
}
bool more_than(int v1,int v2){
    return v1>v2 ? true : false;
}
vector<int> filter(vector<int> &v1,int less_than_value,bool (*pred)(int,int)){
    vector<int> v2;
    vector<int>::iterator it = v1.begin();
    vector<int>::iterator it_end = v1.end();
    for(;it!=it_end;it++){
        if((*pred)(*it,less_than_value)){
            v2.push_back(*it);
        }
    }
    return v2;
}

int count_occ(vector<int> v1,int val){
    int count;
    for(int i=0;i<v1.size();i++){
        if(v1[i] == val){
            count ++;
        }
    }
    return count;
}
int count_occur(vector<int> v1,int val){
    int count;
    vector<int>::iterator it = v1.begin();
    while ((it = find(it,v1.end(),val) )!= v1.end())
    {
        count ++;
        it ++;
    }
    return count;
}

bool isTrue(string a,string b){
    return a.size()> b.size() ? true : false;
}

int main(){
    ifstream ifs("C:\\Users\\Administrator\\Desktop\\Code\\test.txt");
    ofstream ofs("C:\\Users\\Administrator\\Desktop\\Code\\test.txt",ios_base::app);
    if(!ifs || !ofs){
        cerr << "error !" << endl;
    }
    istream_iterator<string> is(ifs);
    istream_iterator<string> eof;
    vector<string> svec;
    copy(is,eof,back_inserter(svec));

    sort(svec.begin(),svec.end(),isTrue);

    vector<string>::iterator it = svec.begin();
    for(; it!=svec.end();it++){
        cout << *it << endl;
    }
}

