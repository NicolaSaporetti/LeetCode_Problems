#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool differenceFound = false;
        bool increasing = true;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                if(!differenceFound)
                {
                    differenceFound = true;
                    increasing = false;
                }
                else if(increasing) return false;
            }
            if(nums[i-1]<nums[i])
            {
                if(!differenceFound)
                {
                    differenceFound = true;
                    increasing = true;
                }
                else if(!increasing) return false;
            }
        }
        return true;
    }
};