#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        vector<vector<int>> dp(k*2+1, vector<int>(prices.size()+1, INT_MIN));
        for(int i=k*2;i>=0;i--)
        {
            for(int j=prices.size();j>=0;j--)
            {
                if(i==k*2 || j==prices.size()) dp[i][j]=0;
                else
                {
                    int profit_next = dp[i][j+1];
                    int profit_buy_sell = dp[i+1][j+1]+((i%2==1)? prices[j] : -prices[j]);
                    dp[i][j]=max(profit_next,profit_buy_sell); 
                }
            }
        }
        return dp[0][0];
    }
};