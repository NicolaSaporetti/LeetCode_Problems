#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> res(sz,-1);
        vector<long long> dp (sz+1,0);
        for(int i=0;i<sz;i++) dp[i+1]=dp[i]+nums[i];
        for(int i=k;i<sz-k;i++) res[i]=(dp[i+k+1]-dp[i-k])/(2*k+1);
        return res;
    }
};