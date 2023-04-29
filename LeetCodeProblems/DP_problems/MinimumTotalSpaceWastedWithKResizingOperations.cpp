#include <vector>
using namespace std;

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        n = nums.size();
        maxWaste = n*1e6;
        memo.assign(n,vector<int>(k+1,-1));
        return dp(nums, 0, k);
    }
private:
    int dp(vector<int>& nums, int pos, int k) {
        if (pos == n) return 0;
        if (k == -1) return maxWaste;
        if (memo[pos][k] != -1) return memo[pos][k];
        int ans = maxWaste;
        int maxNum = nums[pos];
        int totalSum = 0;
        for (int j = pos; j < n; ++j) {
            maxNum = max(maxNum, nums[j]);
            totalSum += nums[j];
            int wasted = maxNum * (j - pos + 1) - totalSum;
            ans = min(ans, dp(nums, j + 1, k - 1) + wasted);
        }
        return memo[pos][k] = ans;
    }

    int n;
    vector<vector<int>> memo;
    int maxWaste;
};