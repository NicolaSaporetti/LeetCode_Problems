#include <vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int sz = nums.size();
        if(sz==1) return {nums[0]};
        vector<pair<int,int>> dp(sz,{1,-1});
        sort(begin(nums),end(nums));
        int maxV = 1;
        for(int i=sz-2;i>=0;i--)
            for(int j=i+1;j<sz;j++)
            {
                if(nums[j]%nums[i]==0)
                {
                    if(1+dp[j].first>dp[i].first)
                    {
                        dp[i].first = dp[j].first+1;
                        dp[i].second= j;
                        maxV = max(maxV,dp[i].first);
                    }
                }
            }
        vector<int> r;
        for(int i=0;i<sz;i++)
            if(dp[i].first==maxV)
            {
                r.push_back(nums[i]);
                int next = dp[i].second;
                while(next!=-1)
                {
                    r.push_back(nums[next]);
                    next = dp[next].second;
                }
                break;
            }
        return r;
    }
};