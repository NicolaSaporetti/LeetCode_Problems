#include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        sz = arr.size();
        maxL = k;
        dp.assign (sz,vector<int>(k,-1));
        return compute(arr, 0,0,0);
    }
private:
    int compute(vector<int>& arr, int start, int len, int maxV)
    {
        if(start+len+1>sz) return 0;
        else if(dp[start][len]!=-1) return dp[start][len];
        else
        {
            int val = max(maxV,arr[start+len]);
            int v1 = (len+1==maxL) ? 0 : compute(arr,start,len+1,val);
            int v2 = val*(len+1) + compute(arr,start+len+1,0,0);
            return dp[start][len]=max(v1,v2);
        }
    }

    int sz;
    vector<vector<int>> dp;
    int maxL;
};