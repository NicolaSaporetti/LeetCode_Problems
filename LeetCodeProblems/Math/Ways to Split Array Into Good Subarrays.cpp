#include <vector>
using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int sz =nums.size();
        long long res = 0;
        int mod = 1e9+7;
        int i=0;
        for(;i<sz;i++)
        {
            if(nums[i]==1) break;
        }
        if(i<sz)
        {
            res = 1;
            while(i<sz)
            {
                int j=0;
                for(i++;i<sz && nums[i]==0;j++,i++);
                if(i>=sz) break;
                else
                {
                    res = (res * (j+1))%mod;
                }
            }
            return res;
        }
        else return 0;
    }
};