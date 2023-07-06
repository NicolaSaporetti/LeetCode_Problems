#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool deleted = false;
        int prev = 0;
        int cur = 0;
        int res = 0;
        for(auto& e : nums)
        {
            if(e==0)
            {
                if(deleted) prev = 0;
                else prev = cur;
                cur = 0;
                deleted = !deleted;
            }
            else
            {
                deleted = false;
                cur++;
                res = max(res, cur+prev);
            }
        }
        return min(res,(int)nums.size()-1);
    }
};