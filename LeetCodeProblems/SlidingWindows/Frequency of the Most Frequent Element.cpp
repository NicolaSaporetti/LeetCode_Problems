#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int res = 1;
        int sz = nums.size();
        sort(begin(nums),end(nums));
        vector<long long> n(sz+1,0);
        for(int i=0;i<sz;i++) n[i+1]=n[i]+(long long)nums[i];
        for(int i=1;i<sz;i++)
        {
            long long needed = nums[i]*(long long)res;
            long long val=n[i+1]-n[i-res+1]+(long long)k;
            for(int j=i-res;j>=0;j--)
            {
                val+=(long long)nums[j];
                needed+=(long long)nums[i];
                if(val>=needed) res++;
                else break;
            }
        }
        return res;
    }
};