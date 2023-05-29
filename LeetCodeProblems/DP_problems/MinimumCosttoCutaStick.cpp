#include <vector>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp.assign(c+1,vector<int>(c+1,-1));
        return helper(1,c,cuts);
    }
private:
    int helper(int start, int end, vector<int> &cuts){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        
        int minm = INT_MAX;
        for(int i=start; i<=end; i++)
        {
            int cost = cuts[end+1] - cuts[start-1] +  helper(start,i-1,cuts) + helper(i+1,end,cuts);
            minm = min(minm, cost);
        }
        
        return dp[start][end] = minm;
    }
    vector<vector<int>> dp;
};