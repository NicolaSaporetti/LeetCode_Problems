#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(begin(nums),end(nums));
        vector<long long> v;
        v.push_back(-1);
        long long res = 0;
        long long sz = nums.size();
        for(int i=0;i<nums.size();i++) if(nums[i]==maxE) v.push_back(i);
        if(v.size()<=k) return 0;
        for(int i=0;i<v.size()-k;i++)
        {
            long long d1 = v[i+1]-v[i];
            long long d2 = nums.size()-v[i+k];
            res+=d1*d2;
        }
        return res;
    }
};