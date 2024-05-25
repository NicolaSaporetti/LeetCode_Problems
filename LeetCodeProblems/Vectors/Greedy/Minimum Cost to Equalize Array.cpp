#include <vector>
using namespace std;

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        long long mv = *max_element(begin(nums),end(nums));
        long long left = 0;
        long long sz = nums.size();
        int mod = 1e9+7;
        long long dist=0;
        long long r = 0;
        for(auto e : nums)
        {
            left+=(mv-e);
            dist=max(dist,mv-e);
        }
        if(cost2>=2*cost1)
        {
            return (left*cost1)%mod;
        }
        else
        {
            long long rem = min(left-dist,left/2);
            r=(rem*cost2)%mod;
            dist= max(left-rem*2,dist-rem);
            long long c2 = (sz-1)*cost2;
            if(dist%2==1 && sz%2==0)
            {
                r=(r+cost1)%mod;
                dist--;
            }
            while(dist+1>=(sz-1) && c2<=cost1*(sz-2))
            {
                r=(r+c2)%mod;
                dist-=(sz-2);
            }
            if(dist+1>=sz-1)
            {
                return (r+dist*cost1)%mod;
            }
            else
            {
                if((dist+sz)%2==0)
                {
                    int c3 = min((dist+sz)/2*cost2,cost1*dist);
                    return (r+c3)%mod;
                }
                else
                {
                    int c3 = min((dist+2*sz)/2*cost2,cost1*dist);
                    return (r+c3)%mod;
                }
            }
        }
    }
};