#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sz = nums.size();
        populate(nums);
        return solutions;
    }

private:
    void populate(vector<int>& nums)
    {
        if(temp.size()==sz) solutions.push_back(temp);
        else
        {
            for(int i=0;i<sz;i++)
            {
                bool isFound = false;
                for(int j=0;j<temp.size();j++)
                    if(temp[j]==nums[i])
                    {
                        isFound = true;
                        break;
                    }
                if(!isFound)
                {
                    temp.push_back(nums[i]);
                    populate(nums);
                    temp.pop_back();
                }
            }
        }
    }

    vector<vector<int>> solutions;
    vector<int> temp;
    int sz;
};