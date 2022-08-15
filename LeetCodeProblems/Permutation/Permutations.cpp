#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int computeSize(int size)
    {
        if(size<=2) return size;
        else
            return size * computeSize(size-1);
    }

    void initialize(int sz, vector<int>& nums)
    {
        solutions.resize(computeSize(sz));
        for(int i=0; i<solutions.size(); i++)
        {
            solutions[i].resize(sz);
        }
        local.resize(nums.size());
        for(int j=0; j<sz; j++)
        {
            local[j] = nums[j];
        }
        index = 0;
    }

    void fillMissingIndexes(vector<int>& missingIndexes, vector<int>& temp)
    {
        vector<int> localTemp;
        localTemp.resize(local.size());
        for(int i=0;i<local.size();i++)
        {
            localTemp[i]=i;
        }
        for(int i=0;i<local.size()-missingIndexes.size();i++)
        {
            localTemp[temp[i]]=-1;
        }
        int j=0;
        for(int i=0;i<local.size();i++)
        {
            if(localTemp[i]!=-1)
            {
                missingIndexes[j++]=localTemp[i];
            }
        }
    }

    void fillCell(int positionToFill, vector<int>& temp)
    {
        vector<int> missingIndexes;
        missingIndexes.resize(local.size()-positionToFill);
        if(positionToFill<local.size())
        {
            fillMissingIndexes(missingIndexes, temp);
        
            for(int i=0;i<local.size()-positionToFill;i++)
            {
                temp[positionToFill]=missingIndexes[i];
                fillCell(positionToFill+1, temp);
            }
        }
        else{
            for(int i=0;i<local.size();i++)
            {
                solutions[index][i]=local[temp[i]];
            }
            index++;
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int sz = nums.size();
        initialize(sz, nums);
        vector<int> temp;
        temp.resize(sz);
        fillCell(0, temp);
        return solutions;
    }

    int index;
    vector<vector<int>> solutions;
    vector<int> local;
};