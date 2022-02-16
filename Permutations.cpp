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
    void fillCell(int* number, vector<vector<int>>& container, vector<int>& nums)
    {
        for(int i=0;i<nums.size();i++)
        {

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solutions;
        int number = nums.size();
        solutions.resize(computeSize(number));
        for(int i=0; i<number; i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                solutions[i][j] = -20;
            }
        }
        fillCell(&number, solutions, nums);
        return solutions;
    }
};

int main()
{
    vector<int> isConnected;
    Solution solution;
    solution.permute(isConnected);
    return 0;
}