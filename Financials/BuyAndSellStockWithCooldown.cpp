#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<int>&prices,int ind, bool buying, vector<vector<int>>&dp)
    {
        if(ind>=prices.size())return 0;
        if(dp[ind][buying] != -1)return dp[ind][buying];
        return dp[ind][buying] = (buying) ? max(dfs(prices,ind+1,!buying,dp) - prices[ind],dfs(prices,ind+1,buying,dp)) : max(dfs(prices,ind+2,!buying,dp) + prices[ind],dfs(prices,ind+1,buying,dp));
    }
    
    int maxProfit(vector<int>& prices){
        vector<vector<int>>dp(prices.size()+10,vector<int>(2,-1));
        return dfs(prices,0,true,dp);
    }
};