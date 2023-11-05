#include <vector>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int res = 0;
        sz = nums.size();
        for(int i=1;i<sz-1;i++)
        {
            int l1 = compute(i-1,nums,nums[i]);
            int l2 = computeR(i+1,nums,nums[i]);
            if(l1>0 && l2>0) res = max(res,l1+l2+1);
        }
        return sz-res;
    }
private:
    int compute(int e, vector<int>& nums, int M)
    {
        vector<int> d;
        for(int i=0;i<=e;i++)
        {
            if(nums[i]>=M) continue;
            int pos = lower_bound(begin(d),end(d),nums[i])-begin(d);
            if(pos>=d.size()) d.push_back(nums[i]);
            else d[pos]=nums[i];
        }
        return d.size();
    }
    int computeR(int b, vector<int>& nums, int M)
    {
        vector<int> d;
        for(int i=sz-1;i>=b;i--)
        {
            if(nums[i]>=M) continue;
            int pos = lower_bound(begin(d),end(d),nums[i])-begin(d);
            if(pos>=d.size()) d.push_back(nums[i]);
            else d[pos]=nums[i];
        }
        return d.size();
    }
    
    int sz;
};