#include <vector>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]*2>upper) break;
            auto it = lower_bound(begin(nums),end(nums),max(nums[i],lower-nums[i]));
            auto it2 = upper_bound(begin(nums),end(nums),upper-nums[i]);
            if(it2!=nums.begin()) it2--;
            int dist1 = max((int)(it-nums.begin()),i+1);
            int dist2 = it2-nums.begin();
            if(dist1>dist2) continue;
            res+=(long long)(dist2-dist1+1);
        }
        return res;
    }
};