#include <vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for(int i=start;i<nums.size();i++)
            if(nums[i]==target)
            {
                res = i-start;
                break;
            }
        for(int i=start-1;i>=0;i--)
            if(nums[i]==target)
            {
                if(start-i<res) return start-i;
                break;
            }
        return res;
    }
};