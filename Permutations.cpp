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

    void initialize(vector<vector<int>>& container, int sz)
    {
        container.resize(computeSize(sz));
        for(int i=0; i<container.size(); i++)
        {
            container[i].resize(sz);
            for(int j=0; j<sz; j++)
            {
                container[i][j] = -20;
            }
        }
    }

    void fillCell(int posionToFill, vector<vector<int>>& container, vector<int>& nums)
    {
        if (posionToFill==nums.size())
        {
            for(int i=posionToFill;i<nums.size();i++)
            {
                fillCell(posionToFill+1, container, nums);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solutions;
        int sz = nums.size();
        initialize(solutions, sz);
        fillCell(0, solutions, nums);
        return solutions;
    }
};

int main()
{
    vector<int> numbers = {0,1,2};
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