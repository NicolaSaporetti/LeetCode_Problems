#include <vector>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long p =nums[0]+((nums[0]%2==0)? 0 : -x);
        long long d =nums[0]+((nums[0]%2==1)? 0 : -x);
        for(int i=1;i<nums.size();i++)
        {
            long long e = nums[i];
            if(e%2==0) p = max(p+(long long)e,d+(long long)e-(long long)x);
            else d = max(d+(long long)e,p+(long long)e-(long long)x);
        }
        return max(p,d);
    }
};