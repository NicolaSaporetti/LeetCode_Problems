#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int sz = nums.size();
        bool switchDone = false;
        for(int i=1;i<sz;i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(!switchDone)
                {
                    if(i-1==0)
                        nums[i-1]=nums[i];
                    else
                        if(nums[i]>=nums[i-2]) nums[i-1] =nums[i];
                        else nums[i]=nums[i-1];
                    switchDone = true;
                }
                else return false;
            }
        }
        return true;
    }
};