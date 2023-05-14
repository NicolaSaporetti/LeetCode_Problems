#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector<vector<int>> dp(sz1+1,vector<int>(sz2+1,0));
        for(int i=0;i<sz1;i++)
        {
            for(int j=0;j<sz2;j++)
            {
                if(nums1[i]==nums2[j]) dp[i+1][j+1]=dp[i][j]+1;
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[sz1][sz2];
    }
};