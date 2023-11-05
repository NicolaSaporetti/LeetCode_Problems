#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int st = 0;
        unordered_set<int> s;
        int r = 0;
        int t = 0;
        for(auto& e : nums)
        {
            t+=e;
            while(s.count(e)>0)
            {
                s.erase(nums[st]);
                t-=nums[st++];
            }
            s.insert(e);
            r = max(r,t);
        }
        return r;
    }
};