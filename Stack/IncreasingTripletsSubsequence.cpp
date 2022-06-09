class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int Max = INT_MIN;
        int mid = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>=Max)
            {
                Max = nums[i];
            }
            else if(nums[i]>=mid)
            {
                mid = nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};