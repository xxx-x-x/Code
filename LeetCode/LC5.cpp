#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m1;
        vector<int>::iterator it_b = nums.begin();
        vector<int>::iterator it_e = nums.end();
        for(;it_b!=it_e;it_b++){
            m1[*it_b]++;
        }
        map<int,int>::iterator it_m = m1.begin();
        for(;it_m!=m1.end();it_m++){
            if(it_m->second == 1){
                return it_m->first;
            }
        } 
        return 0;
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator it_b = nums.begin();
        int result = 0;
        for(;it_b!=nums.end();it_b++){
            result = *it_b ^ result;
        }
        return result;
    }
};
