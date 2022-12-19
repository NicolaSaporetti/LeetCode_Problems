#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int numNeeded = target-nums[i];
            if(m.find(numNeeded)!=m.end()) return {i,m[numNeeded]};
            m[nums[i]]=i;
        }
        return {};
    }
};