#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

//创建新数组，然后交换
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> temp;
        for(int i=0;i<size;i++){
            temp.push_back(nums[i]);
        }
        for(int i=0;i<size;i++){
            nums[(i+k)%size] = temp[i];
        }
    }
};

//多次反转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>::iterator it_b = nums.begin();
        vector<int>::iterator it_e = nums.end();
        reverse(it_b,it_e);
        reverse(it_b,it_b+k%(nums.size()));
        reverse(it_b+k%(nums.size()),it_e);
    }
};

