#include <vector>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int sz = nums.size();
        long long res = 0;
        for(int i=0;i<sz;i++)
        {
            int minv = INT_MAX;
            int maxv = INT_MIN;
            for(int j=i;j<sz;j++)
            {
                minv = min(minv,nums[j]);
                maxv = max(maxv,nums[j]);
                res+=((long long)maxv-(long long)minv);
            }
        }
        return res;
    }
};