#include <vector>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        szm = multipliers.size();
        dp.assign(szm,vector<int>(szm,-1));
        return compute(nums,multipliers,0,0);
    }
private:
    int compute(vector<int>& nums, vector<int>& multipliers, int num, int front) {
        if(num>=szm) return 0;
        else if(dp[num][front]!=-1) return dp[num][front];
        else
        {
            int back = nums.size()-1+front-num;
            int val1 = nums[front]*multipliers[num]+compute(nums,multipliers,num+1,front+1);
            int val2 = nums[back]*multipliers[num]+compute(nums,multipliers,num+1,front);
            return dp[num][front]=max(val1,val2);
        }
    }
    
    int szm;
    vector<vector<int>> dp;
};