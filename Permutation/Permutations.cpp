#include <iostream>
#include <stdlib.h>
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
            cout<<"Index "<<i<<" used"<<endl;
        }
        int j=0;
        cout<<"missingIndexes ("<<missingIndexes.size()<<"): ";
        for(int i=0;i<local.size();i++)
        {
            if(localTemp[i]!=-1)
            {
                missingIndexes[j++]=localTemp[i];
                cout<<missingIndexes[j-1]<<" ";
            }
        }
        cout<<endl;
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
            cout<<"Adding solution "<<index<<": ";
            for(int i=0;i<local.size();i++)
            {
                solutions[index][i]=local[temp[i]];
                cout<<solutions[index][i]<<" ";
            }
            cout<<endl;
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

int main()
{
    vector<int> numbers = {1,1,3,4};
    Solution solution;
    vector<vector<int>> permutations = solution.permute(numbers);
    for(int i=0;i<permutations.size(); i++)
    {
        cout<<"\nCombination: "<<i<<endl;
        for (int j=0;j<permutations[i].size();j++)
        {
            cout<<permutations[i][j]<<" ";
        }
    }
    return 0;
}