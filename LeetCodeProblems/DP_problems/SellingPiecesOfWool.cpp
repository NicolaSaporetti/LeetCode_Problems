#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    long long mxprice(int rows,int columns){
        if(dp[rows][columns]!=-1) return dp[rows][columns];
        
        if(rows==1 && columns==1)
        {
            dp[rows][columns] = price[1][1];
            return price[1][1];
        }
        
        long long ans = price[rows][columns];
        for(int i=1;i<=rows/2;i++)
            ans = max(ans,mxprice(i,columns)+mxprice(rows-i,columns));
        
        for(int i=1;i<=columns/2;i++)
            ans = max(ans,mxprice(rows,i)+mxprice(rows,columns-i));
        dp[rows][columns] = ans;
        return ans;
    }
    
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        dp.assign(m+1,vector<long long>(n+1,-1));
        price.assign(m+1,vector<long long>(n+1,0));
        
        for(int i=0;i<prices.size();i++)
            price[prices[i][0]][prices[i][1]] = prices[i][2];
        
        return mxprice(m,n);
    }

private:
    vector<vector<long long>> dp;
    vector<vector<long long>> price;
};