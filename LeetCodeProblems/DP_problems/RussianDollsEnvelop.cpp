#include <vector>
using namespace std;

bool LISfunction (vector<int>& first ,vector<int>& second) {
    return (first[0]==second[0])? first[1]>second[1]:first[0]<second[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),LISfunction);
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