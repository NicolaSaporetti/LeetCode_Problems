#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        for(auto& el : m)
        {
            int numNeeded = target-el.first;
            if(m.find(numNeeded)!=m.end())
            {
                if(numNeeded!=el.first)
                {
                    res = {el.second[0],m[numNeeded][0]};
                    break;
                }
                else if(el.second.size()>1)
                {
                    res = {el.second[0],el.second[1]};
                    break;
                }
            }
        }
        return res;
    }
};