#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res = 0;
        int s = 0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            while(m[nums[i]]>k) m[nums[s++]]--;
            res = max(res,i-s+1);
        }
        return res;
    }
};