#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum =0;
        int sz = nums.size();
        for(auto e : nums) sum+=e;
        int r = 0;
        if(sum<target)
        {
            int rem = target/sum;
            target-=sum*rem;
            r+=sz*rem;
        }
        for(int i=0;i<sz;i++) nums.push_back(nums[i]);
        int start = 0;
        int add = INT_MAX;
        for(int i=0;i<sz*2;i++)
        {
            target-=nums[i];
            while(target<0)
            {
                target+=nums[start++];
            }
            if(0==target) add = min(add,i-start+1);
        }
        return (add==INT_MAX)? -1 : add+r;
    }
};