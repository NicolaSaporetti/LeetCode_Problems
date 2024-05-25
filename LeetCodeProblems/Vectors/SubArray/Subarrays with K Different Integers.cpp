#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        sz = nums.size();
        return countSubarraysWithAtMostKDistinct(nums,k)-countSubarraysWithAtMostKDistinct(nums,k-1);
    }
private:
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        int i=0;
        int r=0;
        for(int j=0;j<sz;j++)
        {
            mp[nums[j]]++;
            while(mp.size()>k && i<=j)
            {
                if(--mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            r += (j-i+1);
        }
        return r;
    }
    int sz;
};