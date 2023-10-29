#include<stdio.h>
#include<vector>
#include<iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.begin()+1;
        for(;right!=nums.end();right++){
            if(*left!=*right){
                left++;
                *left = *right;
            }
        }
        return left - nums.begin() + 1;
    }
};