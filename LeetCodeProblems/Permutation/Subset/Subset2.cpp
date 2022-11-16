#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        logSubset(nums,0);
        return solutions;
    }
    
private:
    void logSubset(vector<int>& nums, int start)
    {
        solutions.push_back(sol);
        int prev = INT_MIN;
        for(int i=start;i<nums.size();i++)
        {
            if(nums[i]!=prev)
            {
                sol.push_back(nums[i]);
                logSubset(nums,i+1);
                sol.pop_back();
            }
            prev = nums[i];
        }
    }
    
    vector<vector<int>> solutions;
    vector<int> sol;
};