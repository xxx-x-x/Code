#include<stdio.h>
#include<vector>
#include<iterator>
#include<algorithm>
#include<list>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> l1;
        vector<int>::iterator it_1 = nums1.begin();
        vector<int>::iterator it_2 = nums2.begin();
        while (it_1!=nums1.end() && it_2!=nums2.end())
        {
            if(*it_1 == *it_2){
                l1.push_back(*it_1);
                it_1 ++;
                it_2 ++;
            }else if(*it_1 < *it_2){
                it_1++;
            }else if(*it_1 > *it_2){
                it_2++;
            }
        }
        return l1;
    }
};
