#include <vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0]<rhs[0] || (lhs[0]==rhs[0] && lhs[1]>=rhs[1]);});
        vector<int> dp;
        for (int i=0;i<envelopes.size();i++) {
            int height = envelopes[i][1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};