#include <vector>
using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int sz = nums.size();
        long long res = 0;
        for(int i=0;i<sz/2;i++)
        {
            res+=(long long)(get_size(nums[sz-1-i])*nums[i]+nums[sz-1-i]);
        }
        if(sz%2==1) res+=(long long)(nums[sz/2]);
        return res;
    }
    int get_size(int num)
    {
        int res = 1;
        while(num>0)
        {
            res*=10;
            num/=10;
        }
        return res;
    }
};