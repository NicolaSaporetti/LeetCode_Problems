#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> mp;
        int uni = 0;
        long long res = 0;
        long long sum = 0;
        int sz = nums.size();
        for(int i=0;i<k-1;i++)
        {
            sum+=(long long)nums[i];
            if(mp.count(nums[i])==0) uni++;
            mp[nums[i]]++;
        }
        for(int i=k-1;i<sz;i++)
        {
            sum+=(long long)nums[i];
            if(mp.count(nums[i])==0) uni++;
            mp[nums[i]]++;
            if(uni>=m) res = max(res,sum);
            mp[nums[i-k+1]]--;
            sum-=nums[i-k+1];
            if(mp[nums[i-k+1]]==0)
            {
                uni--;
                mp.erase(nums[i-k+1]);
            }
        }
        return res;
    }
};