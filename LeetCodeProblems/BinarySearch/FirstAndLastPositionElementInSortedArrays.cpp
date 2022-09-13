#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result = {-1,-1};
        if(nums.size()!=0)
        {
            int indexL = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int indexH = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(indexL>=nums.size() || nums[indexL]!=target) return result;
            else
            {
                result[0]=indexL;
                result[1]=indexH-1;
            }
        }
        return result;
    }
};