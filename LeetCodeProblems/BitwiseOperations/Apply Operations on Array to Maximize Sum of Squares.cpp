#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> v(31,0);
        long long res = 0;
        int mod = 1e9+7;
        for(auto e : nums)
            for(int i=0;i<=30;i++)
            {
                if((1<<i)&e) v[i]++;
            }
        for(int i=0;i<k;i++)
        {
            long long num = 0;
            for(int i=0;i<31;i++)
            if(v[i])
            {
                num|=(1<<i);
                v[i]--;
            }
            num*=num;
            res=(res+num)%mod;
        }
        return res;
    }
};