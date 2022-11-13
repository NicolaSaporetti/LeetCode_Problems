#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        temp_sum=0;
        this->target = target;
        addNumber(candidates,0);
        return solutions;
    }
private:
    void addNumber(vector<int>& candidates, int index_start) {
        if(temp_sum==target) solutions.push_back(temp);
        else if(temp_sum<target)
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

    int temp_sum;
    vector<vector<int>> solutions;
    vector<int> temp;
    int target;
};