#include <vector>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int z1 = 0;
        int z2 = 0;
        long long v1 =0;
        long long v2 =0;
        for(auto e : nums1)
        {
            if(e>0) v1+=(long long)e;
            else z1++;
        }
        for(auto e : nums2)
        {
            if(e>0) v2+=(long long)e;
            else z2++;
        }
        v1+=(long long)z1;
        v2+=(long long)z2;
        if((v1>v2 && z2==0) || (v2>v1 && z1==0)) return -1;
        return max(v1,v2);
    }
};