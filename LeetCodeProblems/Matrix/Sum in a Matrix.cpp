#include <vector>
using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int r = 0;
        for(int i=0;i<nums.size();i++) sort(begin(nums[i]),end(nums[i]));
        for(int i=0;i<nums[0].size();i++)
        {
            vector<int> v;
            for(int j=0;j<nums.size();j++) v.push_back(nums[j][i]);
            sort(begin(v),end(v));
            r+=v.back();
        }
        return r;
    }
};