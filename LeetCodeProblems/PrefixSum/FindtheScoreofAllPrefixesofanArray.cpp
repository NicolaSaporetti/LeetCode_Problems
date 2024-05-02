#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int mv = 0;
        vector<long long> r;
        long long p = 0;
        for(int i=0;i<nums.size();i++)
        {
            mv = max(mv,nums[i]);
            int v = nums[i]+mv;
            p+=(long long)v;
            r.push_back(p);
        }
        return r;
    }
};