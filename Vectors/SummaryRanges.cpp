#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int i=0;
        sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            int start = i;
            while(sz>i+1 && nums[i+1]==nums[i]+1) i++;
            if(start ==i) result.push_back(to_string(nums[start]));
            else result.push_back(to_string(nums[start])+"->"+to_string(nums[i]));
        }
        return result;
    }
private:
    int sz;
};