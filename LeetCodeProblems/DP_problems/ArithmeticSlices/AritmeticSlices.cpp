#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int result = 0;
        int start = 0;
        int diff = -2000;
        for(int i=1;i<nums.size();i++)
        {
            int newdiff = nums[i]-nums[i-1];
            if(newdiff!=diff)
            {
                start = i-1;
                diff = newdiff;
            }
            result+=(i-start-1);
        }
        return result;
    }
};