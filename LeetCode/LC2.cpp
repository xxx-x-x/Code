#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath.h>

using namespace std;
/**
 * @brief 
 * dp[i][0] 表示 手里没  股票时的利润
 * dp[i][1] 表示 手里有  股票时的利润
 * 
 * 今天股市 收市  分为两种情况：
 * 一，手里有股票
 *  1，昨天有，今天还有     dp[i][1] = dp[i-1][1];
 *  2，昨天没有，今天刚买   dp[i][1] = dp[i-1][0] - prices[i];
 * 二，手里没股票
 *  1，昨天没有，今天没有   dp[i][0] = dp[i-1][0];
 *  2，昨天有，今天刚卖     dp[i][0] = prices[i] + dp[i-1][1];
 * 
 * 边界条件：
 *  dp[0][1] = -prices[0];
 *  dp[0][0] = 0; 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int length = prices.size();
        int (*dp)[2] = new int[length][2];
        for(int i=0;i<length;i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<length;i++){
            dp[i][0] = max(dp[i-1][0],prices[i] + dp[i-1][1]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        }
        return dp[length-1][0];
    }
};