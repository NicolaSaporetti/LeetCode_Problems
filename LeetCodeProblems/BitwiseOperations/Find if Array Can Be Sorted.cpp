#include <vector>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int start = 0;
        int setB= __builtin_popcount(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(__builtin_popcount(nums[i])!=setB)
            {
                sort(begin(nums)+start,begin(nums)+i);
                start = i;
                setB= __builtin_popcount(nums[i]);
            }
        }
        sort(begin(nums)+start,end(nums));
        for(int i=1;i<nums.size();i++) if(nums[i]<nums[i-1]) return false;
        return true;
    }
};