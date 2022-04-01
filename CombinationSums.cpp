#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    void addNumber(vector<int>& candidates, int index_start) {
        if(temp_sum>=target)
        {
            if(temp_sum==target)
            {
                solutions.push_back(temp);
            }
            return;
        }
        else
        {
            for(int i=index_start;i<candidates.size();i++)
            {
                temp.push_back(candidates[i]);
                temp_sum+=candidates[i];
                addNumber(candidates, i);
                temp.pop_back();
                temp_sum-=candidates[i];
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solution_index=0;
        temp_sum=0;
        this->target=target;
        addNumber(candidates,0);
        return solutions;
    }

    int solution_index;
    int target;
    int temp_sum;
    vector<vector<int>> solutions;
    vector<int> temp;
};

int main()
{
    vector<int> numbers = {1,2,3};
    Solution solution;
    vector<vector<int>> solutions = solution.combinationSum(numbers,7);
    return 0;
}