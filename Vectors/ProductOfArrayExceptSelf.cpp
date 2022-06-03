class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        int zeroNumbers = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
            {
                prod*=nums[i];
            }
            else
            {
                zeroNumbers++;
            }
        }
        if(!zeroNumbers)
        {
            for(int i=0;i<nums.size();i++)
            {
                nums[i]=prod/nums[i];
            }
        }
        else if(zeroNumbers==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]) nums[i]=0;
                else nums[i]=prod;
            }
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]) nums[i]=0;
            }
        }
        return nums;
    }
};