#include <vector>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum1 = 0;
        long long sum2 = 0;
        for(auto & e : nums1) sum1+=(long long)(e);
        for(auto & e : nums2) sum2+=(long long)(e);
        long long tot = 0;
        if(sum1==sum2)
        {
            for(int i=0;i<nums1.size();i++)
            {
                long long diff = abs(nums1[i]-nums2[i]);
                if(diff==0) continue;
                if((diff!=0 && k==0) || diff%k!=0) return -1;
                else tot+=(diff/k);
            }
            return tot/2;
        }
        else return -1;
    }
};