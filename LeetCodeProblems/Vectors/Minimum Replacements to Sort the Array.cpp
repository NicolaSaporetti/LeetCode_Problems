#include <vector>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long replacements = 0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                int div = nums[i]/nums[i+1] + ((nums[i]%nums[i+1]==0) ? 0 : 1);
                replacements+=(long long) (div-1);
                nums[i]/=div;
            }
        }
        return replacements;
    }
};