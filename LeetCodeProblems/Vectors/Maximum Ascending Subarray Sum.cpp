#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int prev = 0;
        int res = 0;
        int t = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>prev) t+=nums[i];
            else t = nums[i];
            res = max(res,t);
            prev = nums[i];
        }
        return res;
    }
};