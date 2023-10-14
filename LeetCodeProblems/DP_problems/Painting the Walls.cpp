#include <vector>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        sz = cost.size();
        dp.assign(sz+1,vector<int>(sz+1,-1));
        return solve(cost, time, 0, sz);
    }
private:
    int solve(vector<int>& cost, vector<int>& time, int i, int bank){
        if(bank <= 0) return 0;
        if(i >= cost.size()) return 1e9;
        if(dp[i][bank] != -1) return dp[i][bank];
        else {
            int notTake = solve(cost, time, i+1, bank);
            int take = cost[i] + solve(cost, time, i+1, bank -  time[i] -1); 
            return dp[i][bank] = min(notTake, take);      
        }
    }

    int sz;
    vector<vector<int>> dp;
};