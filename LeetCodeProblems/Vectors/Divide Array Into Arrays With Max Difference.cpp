#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        vector<vector<int>> v;
        for(int i=0;i<nums.size()/3;i++)
        {
            v.push_back({nums[i*3],nums[i*3+1],nums[i*3+2]});
            if(nums[i*3+0]+k<nums[i*3+2]) return {};
        }
        return v;
    }
};