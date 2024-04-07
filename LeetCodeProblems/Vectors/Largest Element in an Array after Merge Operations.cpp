#include <vector>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long left = 0;
        long long res = nums.back();
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1]+left) left+=(long long)nums[i+1];
            else left = 0;
            res = max(res,nums[i]+left);
        }
        return res;
    }
};   