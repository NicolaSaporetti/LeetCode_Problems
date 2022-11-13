#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result = 0;
        int difference = INT_MAX;
        for(int l=0;l<nums.size()-2;l++)
        {
            if(l>0 && nums[l]==nums[l-1]) continue;
            int m=l+1;
            int r = nums.size()-1;
            while(m<r)
            {
                int sum = nums[l]+nums[m]+nums[r];
                if(abs(sum-target)<difference)
                {
                    difference = abs(sum-target);
                    result = sum;
                }
                if(sum == target) {
                    return sum;
                }
                else if(sum < target)
                {
                    while (m < r && nums[m] == nums[m+1]) m++;
                    m++;
                }
                else
                {
                    while (m < r && nums[r] == nums[r-1]) r--;
                    r--;
                }
            }
        }
        return result;
    }
};