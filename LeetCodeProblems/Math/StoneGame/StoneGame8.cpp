#include <vector>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int sz = stones.size();
        vector<int> dp(sz+1,0);
        int result = INT_MIN;
        for(int i=0;i<sz;i++) dp[i+1]=dp[i]+stones[i];
        vector<int> res(sz,0);
        res.back() = dp.back();
        int maxv = dp.back();
        for(int i=sz-2;i>=1;i--)
        {
            res[i]=dp[i+1]-maxv;
            maxv = max(maxv,res[i]);
        }
        for(int i=1;i<sz;i++) result = max(result,res[i]);
        return result;
    }
};