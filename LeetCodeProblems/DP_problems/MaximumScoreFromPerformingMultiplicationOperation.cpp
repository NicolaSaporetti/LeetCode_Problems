#include <vector>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int sz = nums.size();
        int msz = multipliers.size();
        vector<vector<int>> dp(msz+1,vector<int>(msz+1,0));
        for (int op = msz-1; op >= 0; op--) {
            for (int left = op; left >= 0; left--) {
                dp[op][left] = max(multipliers[op] * nums[left] + dp[op + 1][left + 1],
                                   multipliers[op] * nums[sz - 1 - (op - left)] + dp[op + 1][left]);
            }
        }
        return dp[0][0];
    }
};