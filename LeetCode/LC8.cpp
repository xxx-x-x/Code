#include<stdio.h>
#include<vector>
#include<iterator>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> num;
        int zero = 0;
        vector<int>::iterator it = nums.begin();
        for(;it!=nums.end();it++){
            if(*it!=0){
                num.push_back(*it);
            }else{
                zero += 1;
            }
        }
        num.insert(num.end(),zero,0);
        nums = num;
    }
};