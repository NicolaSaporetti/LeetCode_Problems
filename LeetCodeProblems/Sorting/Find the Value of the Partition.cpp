#include <vector>
using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int r = INT_MAX;
        for(int i=0;i<nums.size()-1;i++) r = min(nums[i+1]-nums[i],r);
        return r;
    }
};