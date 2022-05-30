class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> dp(nums.size());
        stack<int> myS;
        stack<int> myS2;
        int tot = 0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!myS.empty() && nums[i]>myS.top())
            {
                dp[i] = max(dp[i]+1,dp[myS2.top()]);
                myS.pop();
                myS2.pop();
                tot = max(dp[i], tot);
            }
            myS.push(nums[i]);
            myS2.push(i);
        }
        return tot;
    }
};