#include <vector>
using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 1;
        long long start = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                res++;
                start = i;
            }
            else res+=(i-start+1);
        }
        return res;
    }
};