#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        for(int i=0;i<nums.size();i++) dp[i+1]=nums[i]+dp[i];
        for(int i=0;i<nums.size();i++) if(dp[nums.size()]-dp[i+1]==dp[i]) return i;
        return -1;
    }
};