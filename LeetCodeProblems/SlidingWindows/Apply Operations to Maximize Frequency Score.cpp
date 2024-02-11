#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int i = 0;
        int res = 0;
        int sz = nums.size();
        long long cur = 0;
        sort(begin(nums),end(nums));
        for (int j = 0; j < sz; ++j)
        {
            cur += nums[j] - nums[(i + j) / 2];
            while (cur > k) {
                cur -= nums[(i + j + 1) / 2] - nums[i];
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};