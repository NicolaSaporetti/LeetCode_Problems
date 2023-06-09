#include <vector>
using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int p=-1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>=nums[i])
            {
                if(p!=-1) return false;
                else p = i-1;
            }
        }
        if(p!=-1)
        {
            return isCor(nums, p) || isCor(nums, p+1);
        }
        return true;
    }
private:
    bool isCor(vector<int> nums,int p)
    {
        for(int i=p;i<nums.size()-1;i++) nums[i]=nums[i+1];
        nums.resize(nums.size()-1);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>=nums[i]) return false;
        }
        return true;
    }
};