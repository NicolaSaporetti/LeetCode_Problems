#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        for(;i-2>=0;i--)
        {
            if(nums[i]<nums[i-1]+nums[i-2]) break;
        }
        if(i>=2) return nums[i]+nums[i-1]+nums[i-2];
        else return 0;
    }
};