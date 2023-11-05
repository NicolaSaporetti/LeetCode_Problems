#include <vector>
using namespace std;

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<long long> v(sz+3,0);
        for(int i=0;i<sz;i++)
        {
            int e = max(0,k-nums[i]);
            v[i+3]=min(v[i],min(v[i+1],v[i+2]));
            v[i+3]+=(long long)e;
        }
        return min(v[sz+2],min(v[sz+1],v[sz]));
    }
};