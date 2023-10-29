#include<stdio.h>
#include<vector>
#include<iterator>
#include<map>
#include<algorithm>
#include<set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int>::iterator it_b = nums.begin();
        vector<int>::iterator it_b_1;
        vector<int>::iterator it_e = nums.end();
        for(;it_b!=it_e;it_b++){
            it_b_1 = it_b +1;
            for(;it_b_1!=it_e;it_b_1++){
                if(*it_b == *it_b_1){
                    return true;
                }
            }
        }
        return false;
    }
};


using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m1;
        vector<int>::iterator it = nums.begin();
        for(;it!=nums.end();it++){
            m1[*it]++;
        }
        map<int,int>::iterator it_b= m1.begin();
        map<int,int>::iterator it_e = m1.end();
        for(;it_b!=it_e;it_b++){
            if(it_b->second != 1){
                return true;
            }
        } 
        return false;
    }
};

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int>::iterator it_b = nums.begin();
        vector<int>::iterator it_b_1;
        vector<int>::iterator it_e = nums.end();
        sort(it_b,it_e);
        for(it_b_1 = it_b + 1;it_b_1!=it_e;it_b_1++,it_b++){
            if(*it_b_1 == *it_b){
                return true;
            }
        }
        return false;
    }
};

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int>::iterator it_b = nums.begin();
        vector<int>::iterator it_e = nums.end();
        set<int> s1;
        for(;it_b!=it_e;it_b++){
            if(s1.insert(*it_b).second == false){
                return true;
            }
        }
        return false;
    }
};

