#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int res = 0;
        vector<int> result;
        for(auto& n : nums) res^=n;
        for(int i=nums.size()-1;i>=0;i--)
        {
            result.push_back(compute(res, maximumBit));
            res^=nums[i];
        }
        return result;
    }
    int compute(int res, int maximumBit)
    {
        int k = 0;
        for(int i=0;i<maximumBit;i++)
        {
            if((res&(1<<i))==0) k|=(1<<i);
        }
        return k;
    }
};