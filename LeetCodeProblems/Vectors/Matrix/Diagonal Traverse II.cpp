#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int tot=0;
        vector<int> res;
        int sz = 0;
        for(int i=0;i<nums.size();i++)
            for(int j=0;j<nums[i].size();j++) sz = max(sz,i+j);
        vector<vector<int>> v(sz+1);
        for(int i=0;i<nums.size();i++)
            for(int j=0;j<nums[i].size();j++)
            {
                v[i+j].push_back(nums[i][j]);
            }
        for(int i=0;i<v.size();i++)
            for(int j=v[i].size()-1;j>=0;j--) res.push_back(v[i][j]);
        return res;
    }
};