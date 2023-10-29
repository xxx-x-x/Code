#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<fstream>
using namespace std;

class isTrue
{
public:
    bool operator() (int elem){
        return elem%2 ? false : true;
    }
};
// 使用输入输出迭代器进行赋值
int main(){
    vector<int> ivec;
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    copy(is,eof,back_inserter(ivec));
    vector<int>::iterator par = partition(ivec.begin(),ivec.end(),isTrue());
    ofstream ofs1("C:\\Users\\Administrator\\Desktop\\Code\\test1.txt");
    ofstream ofs2("C:\\Users\\Administrator\\Desktop\\Code\\test2.txt");
    if(!ofs1 || !ofs2){
        cerr<< " error " << endl;
        return -1;
    }
    ostream_iterator<int> os1(ofs1," ");
    ostream_iterator<int> os2(ofs2," ");
    copy(ivec.begin(),par,os1);
    copy(par,ivec.end(),os2);
}