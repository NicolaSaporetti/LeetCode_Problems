#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums),end(nums));
        long long sz = nums.size();
        vector<long long> v(sz+1,0);
        vector<long long> res;
        for(int i=0;i<sz;i++)
        {
            v[i+1]=nums[i];
            v[i+1]+=v[i];
        }
        for(auto& query : queries)
        {
            long long el = upper_bound(begin(nums),end(nums),query)-begin(nums);
            long long val = (el>0)? (el*(long long)query)-v[el] : 0;
            long long val2 = (el<sz)? ((v.back()-v[el])-(sz-el)*(long long)query) : 0;
            res.push_back(val+val2);
        }
        return res;
    }
};