#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int sz = nums.size();
        vector<long long> sum(sz,0);
        vector<long long> n2(sz,0);
        n2[0]=nums[0];
        sum[0]=2*n2[0];
        for(int i=1;i<sz;i++)
        {
            n2[i]=max(n2[i-1],(long long)nums[i]);
            sum[i]=(long long)nums[i]+n2[i];
        }
        vector<long long> res(sz,0);
        res[0]=sum[0];
        for(int i=1;i<sz;i++) res[i]=res[i-1]+sum[i];
        return res;
    }
};