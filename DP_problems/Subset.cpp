#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> solutions;
    vector<int> sol;
    void logSubset(vector<int>& nums, int start)
    {
        sol.push_back(nums[start]);
        solutions.push_back(sol);
        for(int j=start+1;j<nums.size();j++)
        {
            logSubset(nums,j);
        }
        sol.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        solutions.push_back(sol);
        for(int i=0;i<nums.size();i++)
        {
            logSubset(nums,i);
        }
        return solutions;
    }
};