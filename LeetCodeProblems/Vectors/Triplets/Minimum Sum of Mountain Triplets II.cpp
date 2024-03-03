#include <vector>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int sz = nums.size();
        vector<int> l(sz,0);
        vector<int> r(sz,0);
        int res = INT_MAX;
        l[0]=nums[0];
        r[sz-1]=nums[sz-1];
        for(int i=1;i<sz;i++) l[i]=min(l[i-1],nums[i]);
        for(int i=sz-2;i>=0;i--) r[i]=min(r[i+1],nums[i]);
        for(int i=1;i<sz-1;i++) if(nums[i]>l[i-1] && nums[i]>r[i+1]) res = min(res, nums[i]+l[i-1]+r[i+1]);
        return (res==INT_MAX)? -1 : res;
    }
};