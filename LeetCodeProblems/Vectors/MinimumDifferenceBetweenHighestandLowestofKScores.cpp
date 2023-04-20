#include <vector>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int res = INT_MAX;
        for(int i=k-1;i<nums.size();i++) res = min(res, nums[i]-nums[i-k+1]);
        return res;
    }
};