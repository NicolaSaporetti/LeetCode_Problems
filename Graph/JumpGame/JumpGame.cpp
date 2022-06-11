#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool jump(vector<int>& nums, int index)
    {
        bool result = false;
        if(!numsVisisted[index])
        {
            numsVisisted[index] = true;
            if(index==nums.size()-1) return true;
            for(int i=nums[index];i>=1 && !result;i--)
            {
                if(index+i<nums.size())
                {
                    result = jump(nums,index+i);
                }
            }
        }
        return result;
    }

public:
    bool canJump(vector<int>& nums) {
        numsVisisted.resize(nums.size());
        for(int i=0;i<numsVisisted.size();i++) numsVisisted[i]=false;
        return jump(nums,0);
    }
    vector<bool> numsVisisted;
};