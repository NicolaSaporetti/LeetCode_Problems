#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int t = 1;
        int n = 0;
        int start = 0;
        for(int i=0;i<nums.size();i++)
        {
            t*=nums[i];
            while(t>=k) t/=nums[start++];
            n+=(i-start+1);
        }
        return n;
    }
};