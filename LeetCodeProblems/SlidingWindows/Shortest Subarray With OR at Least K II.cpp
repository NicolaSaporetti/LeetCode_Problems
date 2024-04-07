#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0) return 1;
        vector<int> v(31,0);
        int sz = nums.size();
        int val = 0;
        int start = 0;
        int res = INT_MAX;
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<31;j++)
            {
                if((1<<j)&nums[i])
                {
                    if(v[j]==0) val|=(1<<j);
                    v[j]++;
                }
            }
            if(val>=k)
            {
                do
                {
                    for(int j=0;j<31;j++)
                    {
                        if((1<<j)&nums[start])
                        {
                            v[j]--;
                            if(v[j]==0) val&=~(1<<j);
                        }
                    }
                    start++;
                }
                while(val>=k);
                start--;
                for(int j=0;j<31;j++)
                {
                    if((1<<j)&nums[start])
                    {
                        if(v[j]==0) val|=(1<<j);
                        v[j]++;
                    }
                }
                res = min(res,i-start+1);
            }
        }
        return (res==INT_MAX)? -1 : res;
    }
};