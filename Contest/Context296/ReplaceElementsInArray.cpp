#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<int,int> fM;
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        for(int i=0;i<nums.size();i++)
        {
            fM.insert(make_pair(nums[i],i));
        }
        for(int i=0;i<operations.size();i++)
        {
            auto it = fM.find(operations[i][0]);
            fM.insert(make_pair(operations[i][1],it->second));
            fM.erase(it);
        }
        for(auto it=fM.begin();it!=fM.end();it++)
        {
            nums[it->second] = it->first;
        }
        return nums;
    }
};