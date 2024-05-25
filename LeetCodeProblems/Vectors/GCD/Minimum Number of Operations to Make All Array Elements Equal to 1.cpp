#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        int r = count(begin(nums),end(nums),1);
        if(r>0) return sz-r;
        int res = INT_MAX;
        for(int i=0;i<sz;i++)
        {
            int num = nums[i];
            int j=1;
            while(num!=1 && i+j<sz)
            {
                num=__gcd(num,nums[i+j]);
                j++;
            }
            if(num==1) res = min(res,sz-1+j-1);
        }
        return (res==INT_MAX)? -1 : res;
    }
};