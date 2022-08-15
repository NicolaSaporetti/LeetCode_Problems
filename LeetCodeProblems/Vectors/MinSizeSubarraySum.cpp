#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum =0;
        int count = 0;
        int minimum = INT_MAX;
        int start = 0;
        for(int i=0;i<nums.size();i++)
        {
            count++;
            sum+=nums[i];
            if(sum>=target)
            {
                while((sum-nums[start])>=target)
                {
                    sum-=nums[start];
                    start++;
                    count --;
                }
                minimum = min(count, minimum);
            }
        }
        if(sum<target) minimum = 0;
        return minimum;
    }
};