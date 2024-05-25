#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;
        for(int i=0;i<(1<<nums.size());i++)
        {
            vector<int> t;
            for(int j=0;j<nums.size();j++) if((1<<j)&i) t.push_back(nums[j]);
            r.push_back(t);
        }
        return r;
    }
};