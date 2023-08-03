#include <vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxE = *max_element(begin(nums),end(nums));
        vector<int> dp(maxE+1,0);
        for(auto& e : nums) dp[e]+=e;
        for(int i=2;i<=maxE;i++) dp[i]=max(dp[i-1],dp[i-2]+dp[i]);
        return dp.back();
    }
};