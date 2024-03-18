#include <multiset>
#include <vector>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> ms;
        int r = INT_MAX;
        for(int i=x;i<nums.size();i++) ms.insert(nums[i]);
        for(int i=0;i<nums.size()-x;i++)
        {
            auto it =ms.lower_bound(nums[i]);
            if(it!=ms.end()) r = min(*it-nums[i],r);
            if(it!=ms.begin()) r = min(nums[i]-*prev(it),r);
            it = ms.find(nums[i+x]);
            ms.erase(it);
        }
        return r;
    }
};