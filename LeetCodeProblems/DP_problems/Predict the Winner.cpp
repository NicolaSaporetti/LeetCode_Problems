#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        sz = nums.size();
        dp.assign(sz+1,vector<int>(sz+1,INT_MAX));
        return (computeFirst(0,0,nums)>=0);
    }
private:
    int computeFirst(int move, int front, vector<int>& nums)
    {
        if(dp[move][front]!=INT_MAX) return dp[move][front];
        else
        {
            if(move>=sz) return 0;
            return dp[move][front] = max(nums[sz-1-move+front]+computeSecond(move+1,front,nums),nums[front]+computeSecond(move+1,front+1,nums));
        }
    }
    int computeSecond(int move, int front, vector<int>& nums)
    {
        if(dp[move][front]!=INT_MAX) return dp[move][front];
        else
        {
            if(move>=sz) return 0;
            return dp[move][front]=min(-nums[sz-1-move+front]+computeFirst(move+1,front,nums),-nums[front]+computeFirst(move+1,front+1,nums));
        }
    }

    vector<vector<int>> dp;
    int sz;
};