#include <vector>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int sz = nums.size();
        int p1=0;
        int p2=0;
        int res = 0;
        while(p1<sz)
        {
            while(nums[p1]>nums[p2]+2*k) p2++;
            res = max(res, p1-p2+1);
            p1++;
        }
        return res;
    }
};