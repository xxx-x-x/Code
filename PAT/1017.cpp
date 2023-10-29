#include <iostream>
#include <stdio.h>
#include <map>
#include<algorithm>
#include<vector>
using namespace std;

class win{
    public:
    win(){c = 'P';i=3;}
    win(char c,int i):c(c),i(i){}
    char getC(){
        return c;
    }
    int getI(){
        return i;
    }
    private:
    char c;
    int i;
};

win CMP(const char A,const char B){
    //B > C > J > B
    //1 = jia,2 = yi,3 = ping
    if(A == 'B'&&B =='C') return win(A,1);
    if(A == 'C'&&B =='J') return win(A,1);
    if(A == 'J'&&B =='B') return win(A,1);
    if(A == 'B'&&B =='B') return win(A,3);
    if(A == 'C'&&B =='C') return win(A,3);
    if(A == 'J'&&B =='J') return win(A,3);
    return win(B,2);
}

class less_than{
    public:
    bool operator()(const pair<char,int>& p1,const pair<char,int>& p2){
        return p1.second > p2.second;
    }
};

int main(){
    int num;
    char A,B;
    map<char,int> jia,yi;
    int jia_win = 0,yi_win = 0;
    cin >> num;
    for(int ix=0;ix<num;ix++){
        cin >> A;
        cin >> B;
        if(CMP(A,B).getI()==1){
            jia[CMP(A,B).getC()]++;
            jia_win ++;
        }else if(CMP(A,B).getI()==2){
            yi[CMP(A,B).getC()]++;
            yi_win++;
        }else if(CMP(A,B).getI()==3){
            jia[CMP(A,B).getC()]++;
            yi[CMP(A,B).getC()]++;
        }
    }
    vector<pair<char,int>> jia_v(jia.begin(),jia.end());
    vector<pair<char,int>> yi_v(yi.begin(),yi.end());
    sort(jia_v.begin(),jia_v.end(),less_than());
    sort(yi_v.begin(),yi_v.end(),less_than());
    cout << jia_win << " " << num-jia_win-yi_win << " " << yi_win << endl;
    cout << yi_win << " " << num-jia_win-yi_win << " " << jia_win << endl;
    if(num!=0){
        cout << jia_v[0].first << " " << yi_v[0].first;
    }
    return 0;
}