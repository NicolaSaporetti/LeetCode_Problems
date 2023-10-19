#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> v(31,0);
        int sz = nums.size();
        int r = 0;
        int mod = 1e9+7;
        for(int i=0;i<sz;i++)
        {
            int j=0;
            while(nums[i]>0)
            {
                v[j++]+=nums[i]%2;
                nums[i]/=2;
            }
        }
        for(int i=0;i<k;i++)
        {
            long long n = 0;
            for(int j=30;j>=0;j--)
            {
                n*=2;
                if(v[j]>0)
                {
                    n++;
                    v[j]--;
                }
            }
            n*=n;
            r = (r+(n%mod))%mod;            
        }
        return r;
    }
};