#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int tot = 1;
        int i=1;
        bool increase = true;
        int sz = nums.size();
        while(i<sz && nums[i]==nums[i-1]) i++;
        if(i<sz)
        {
            if(nums[i]<nums[i-1]) increase = false;
            tot++;
        }
        for(i++;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1] && !increase)
            { 
                increase= !increase;
                tot++;
            }
            else if(nums[i]<nums[i-1] && increase)
            {
                increase = !increase;
                tot++;
            }
        }
        return tot;
    }
};