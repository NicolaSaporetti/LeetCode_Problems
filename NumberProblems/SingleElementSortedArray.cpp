#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int sz = nums.size();
        int right = sz-1;
        while(left<right)
        {
            int center = (right+left)/2;
            if(center==0 || (nums[center-1]!=nums[center] && nums[center+1]!=nums[center])) return nums[center];
            else
            {
                if((nums[center-1]==nums[center] && (sz-center)%2==0) ||
                   (nums[center-1]!=nums[center] && (sz-center)%2==1))
                {
                    left = center+1;
                }
                else
                {
                    right = center-1;
                }
            }
        }
        return nums[left];
    }
};