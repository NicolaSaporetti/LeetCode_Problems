#include <vector>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
        long long tot = 0;
        for(auto e : nums) tot+=(long long) e;
        for(int i=nums.size()-1;i>=2;i--)
        {
            if(tot-nums[i]<=nums[i]) tot-=nums[i];
            else return tot;
        }
        return -1;
    }
};