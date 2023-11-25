#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sz = nums.size();
        int res = sz+1;
        vector<int> left(sz+1,0);
        vector<int> right(sz+1,0);
        for(int i=0;i<sz;i++) left[i+1]=left[i]+nums[i];
        for(int i=0;i<sz;i++) right[i+1]=right[i]+nums[sz-1-i];
        for(int i=0;i<=sz;i++)
        {
            int v1 = left[i];
            auto it = lower_bound(begin(right),end(right),x-v1);
            if(it!=end(right) && *it==x-v1)
            {
                int pos = it-begin(right);
                res = min(res,i+pos);
            }
        }
        return (res==sz+1)? -1 : res;
    }
};