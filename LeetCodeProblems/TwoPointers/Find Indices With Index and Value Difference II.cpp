#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int sz = nums.size();
        int minV = INT_MAX;
        int maxV = INT_MIN;
        int minI = -1;
        int maxI = -1;
        for(int i=sz-indexDifference-1;i>=0;i--)
        {
            if(minV>nums[i+indexDifference])
            {
                minV = nums[i+indexDifference];
                minI = i+indexDifference;
            }
            if(maxV<nums[i+indexDifference])
            {
                maxV = nums[i+indexDifference];
                maxI = i+indexDifference;
            }
            if(nums[i]+valueDifference<=maxV) return {i,maxI};
            if(nums[i]-valueDifference>=minV) return {i,minI};
        }
        return {-1,-1};
    }
};