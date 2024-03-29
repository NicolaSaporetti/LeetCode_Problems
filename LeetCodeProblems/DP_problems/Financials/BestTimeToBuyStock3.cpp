#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int transactions = 4;
        vector<vector<int>> dp(transactions+1, vector<int>(prices.size()+1, INT_MIN));
        for(int i=transactions;i>=0;i--)
        {
            for(int j=prices.size();j>=0;j--)
            {
                if(i==transactions || j==prices.size()) dp[i][j]=0;
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