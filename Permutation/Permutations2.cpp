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

    void order()
    {
        for(int i=0; i< local.size(); i++)
        {
            for(int j=i+1; j< local.size(); j++)
            {
                if(local[i]>local[j])
                {
                    int temp = local[j];
                    local[j] = local[i];
                    local[i] = temp;
                }
            }
        }
    }

    void initialize(int sz, vector<int>& nums)
    {
        local.resize(nums.size());
        for(int j=0; j<sz; j++)
        {
            local[j] = nums[j];
        }
        order();
        index = 0;
    }

    vector<int> fillMissingIndexes(vector<int>& temp,int positionToFill)
    {
        vector<int> missingIndexes;
        vector<int> localTemp;
        missingIndexes.resize(local.size()-positionToFill);
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
        int previousNum = -100;
        cout<<"missingIndexes ("<<missingIndexes.size()<<"): "<<endl;
        for(int i=0;i<local.size();i++)
        {
            cout<<"Previous: "<<previousNum<<endl;
            cout<<"Current: "<<local[i]<<endl;
            if(localTemp[i]!=-1 && local[i]!=previousNum)
            {
                cout<<"Adding missing"<<endl;
                previousNum = local[i];
                missingIndexes[j++]=localTemp[i];
                cout<<missingIndexes[j-1]<<" "<<endl;
            }
        }
        missingIndexes.resize(j);
        return missingIndexes;
    }

    void fillCell(int positionToFill, vector<int>& temp)
    {
        if(positionToFill<local.size())
        {
            vector<int> missingIndexes = fillMissingIndexes(temp,positionToFill);
        
            for(int i=0;i<missingIndexes.size();i++)
            {
                temp[positionToFill]=missingIndexes[i];
                fillCell(positionToFill+1, temp);
            }
        }
        else{
            cout<<"Adding solution "<<index<<": ";
            vector<int> tempVec;
            for(int i=0;i<local.size();i++)
            {
                tempVec.push_back(local[temp[i]]);
                cout<<local[temp[i]]<<" ";
            }
            cout<<endl;
            solutions.push_back(tempVec);
            index++;
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    vector<int> numbers = {1,1,2,2};
    Solution solution;
    vector<vector<int>> permutations = solution.permuteUnique(numbers);
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