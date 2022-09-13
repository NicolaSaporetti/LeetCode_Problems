#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> fM;
        for(int i=0;i<nums.size();i++) fM[nums[i]]=i;
        for(int i=0;i<operations.size();i++)
        {
            fM[operations[i][1]] = fM[operations[i][0]];
            fM.erase(operations[i][0]);
        }
        for(auto it=fM.begin();it!=fM.end();it++)
        {
            nums[it->second] = it->first;
        }
        return nums;
    }
};