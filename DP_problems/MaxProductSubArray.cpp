#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int ma=nums[0];
        int mi=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(ma,mi);
            }
            ma=max(ma*nums[i],nums[i]);
            mi=min(mi*nums[i],nums[i]);
            ans=max(ans,ma);
        }
        return ans;
    }
};