#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int s = 0;
        unordered_map<int,int> m;
        int r = 0;
        int t = 0;
        for(auto& e : nums)
        {
            t+=e;
            m[e]++;
            while(m[e]>1)
            {
                m[nums[s]]--;
                t-=nums[s++];
            }
            r = max(r,t);
        }
        return r;
    }
};