#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m1;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int tmp = target-nums[i];
            map<int,int>::iterator it = m1.find(tmp);
            if(it != m1.end()){
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }else{
                m1.insert(pair<int,int>(nums[i],i));
            }
        }
        return {0,0};
    }
};   
    int main(){
        vector<int> n = {1,2,3};
        vector<int> n1(n.begin(),n.end());
        for(int i=0;i<n.size();i++){
            std::cout<< n1[i];
        }
        return 0;
    }