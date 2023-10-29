#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator it_e = digits.end()-1;
        vector<int>::iterator it_b = digits.begin();
        *it_e += 1;
        for(;it_e!=it_b;it_e--){            
            if(*it_e == 10){
                *it_e = 0;
                *(it_e-1)+=1;//i++ 执行错误，但是++i正确
            }else if(*it_e < 10){
                return digits;
            }
        }
        if(*it_b==10){
            vector<int> v1(digits.size()+1,0);
            *(v1.begin())+=1;
            return v1;
        }
        return digits;
    }
};