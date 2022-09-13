#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum =0;
        int wz = 0;
        int minimum = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            wz++;
            sum+=nums[i];
            while((sum-nums[i-wz+1])>=target)
            {
                wz --;
                sum-=nums[i-wz];
            }
            if(sum>=target)
            {
                minimum = min(wz, minimum);
            }
        }
        return (minimum!=INT_MAX) ? minimum : 0;
    }
};