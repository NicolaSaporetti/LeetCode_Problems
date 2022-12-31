#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> res(k,0);
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int value = v[sz-k];
        int tot = 1;
        while(sz-k+tot<sz && v[sz-k+tot]==value) tot++;
        int pos =0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]>value) res[pos++]=nums[i];
            else if(nums[i]==value && tot>0)
            {
                res[pos++]=nums[i];
                tot--;
            }
        }
        return res;
    }
};