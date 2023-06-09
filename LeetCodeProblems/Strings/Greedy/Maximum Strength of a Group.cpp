#include <vector>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        long long res = 1;
        sort(begin(nums),end(nums));
        int neg = count_if(begin(nums),end(nums),[](int el){return el<0;});
        int pos = count_if(begin(nums),end(nums),[](int el){return el>0;});
        if(nums.size()-pos-neg==nums.size()) return 0;
        if(pos==0)
        {
            if(neg==1) return nums[nums.size()-1];
        }
        for(int i=0;i<neg/2;i++)
        {
            res*=(long long)nums[i*2];
            res*=(long long)nums[i*2+1];
        }
        for(int i=neg;i<nums.size();i++)
        {
            if(nums[i]!=0) res*=(long long)nums[i];
        }
        return res;
    }
};