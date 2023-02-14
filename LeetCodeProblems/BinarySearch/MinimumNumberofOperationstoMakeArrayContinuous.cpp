#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz = nums.size()-1;
        int res = 0;
        sort(nums.begin(),nums.end());
        nums.erase(unique(begin(nums),end(nums)),nums.end());
        for(auto it = nums.begin();it!=nums.end();it++)
        {
            auto it2 = upper_bound(it, nums.end(),*it+sz);
            if(it2==nums.end() || *it2>*it+sz) it2--;
            res = max(res, (int)(it2-it)+1);
        }
        return sz+1-res;
    }
};