#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    set<vector<int>> solutions;
    vector<vector<int>> finalSol;
    vector<int> sol;
    void logSubset(vector<int>& nums, int start)
    {
        sol.push_back(nums[start]);
        solutions.insert(sol);
        for(int j=start+1;j<nums.size();j++)
        {
            logSubset(nums,j);
        }
        sol.pop_back();
    }
    
    void fillFinalSol()
    {
        for(auto it=solutions.begin();it!=solutions.end();it++)
        {
            finalSol.push_back(*it);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        solutions.insert(sol);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            logSubset(nums,i);
        }
        fillFinalSol();
        return finalSol;
    }
};

int main()
{
    Solution solution;
    return 0;
}