#include <vector>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int sz = nums.size();
        int s = -1;
        int res = 0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]>threshold) s = -1;
            else
            {
                if(s==-1)
                {
                    if(nums[i]%2==0) s=1;
                }
                else
                {
                    if(nums[i]%2==0)
                    {
                        if(nums[i-1]%2==0) s=1;
                        else s++;
                    }
                    else
                    {
                        if(nums[i-1]%2==1) s = -1;
                        else s++;
                    }
                }
            }
            res = max(res, s);
        }
        return res;
    }
};