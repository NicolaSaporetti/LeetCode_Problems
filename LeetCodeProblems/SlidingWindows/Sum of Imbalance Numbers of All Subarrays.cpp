#include <vector>
using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int sz = nums.size();
        int r = 0;
        for(int i=0;i<sz;i++)
        {
            int minv = nums[i]-1;
            int maxv = nums[i]-1;
            vector<bool> v(sz);
            v[nums[i]-1]=true;
            int inbal = 0;
            for(int j=i+1;j<sz;j++)
            {
                int val = nums[j]-1;
                if(!v[val])
                {
                    if(val<minv)
                    {
                        if(!v[val+1]) inbal++;
                    }
                    else if(val>maxv) 
                    {
                        if(!v[val-1]) inbal++;
                    }
                    else
                    {
                        if(!v[val+1] && !v[val-1]) inbal++;
                        else if(v[val+1] && v[val-1]) inbal--;
                    }
                }
                r+=inbal;
                v[val]=true;
                minv = min(minv,val);
                maxv = max(maxv,val);
            }
        }
        return r;
    }
};