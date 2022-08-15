#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int result;
    int start;
    int diff;

    void updateResult(int i)
    {
        if(i-start+1>=3)
        {
            result+=((i-start-1)*(i-start)/2);
        }
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        result = 0;
        start = 0;
        diff = -2000;
        for(int i=1;i<nums.size();i++)
        {
            int newdiff = nums[i]-nums[i-1];
            if(newdiff!=diff)
            {   
                updateResult(i-1);
                start = i-1;
                diff = newdiff;
            }
        }
        updateResult(nums.size()-1);
        return result;
    }
};