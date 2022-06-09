#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    private:
    void order(vector<int>& vec)
    {
        for(int i=0; i< vec.size(); i++)
        {
            for(int j=i+1; j< vec.size(); j++)
            {
                if(vec[i]>vec[j])
                {
                    int temp = vec[j];
                    vec[j] = vec[i];
                    vec[i] = temp;
                }
            }
        }
    }

    bool is_duplicate()
    {
        bool found = false;
        for(int i=0; i< solutions.size() && !found; i++)
        {
            if(temp.size()==solutions[i].size())
            {
                bool mismatchFound = false;
                for(int j=0;j<temp.size() && !mismatchFound;j++)
                {
                    if(solutions[i][j]!=temp[j])
                    {
                        mismatchFound = true;
                    }
                }
                if(!mismatchFound)
                {
                    found = true;
                }
            }
        }
        return found;
    }

    void addNumber(vector<int>& candidates, int index_start) {
        if(temp_sum>=target)
        {
            if(temp_sum==target && !is_duplicate())
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
                addNumber(candidates, i+1);
                temp.pop_back();
                temp_sum-=candidates[i];
                for(; i+1<candidates.size() && candidates[i]==candidates[i+1];i++);
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        solution_index=0;
        temp_sum=0;
        this->target=target;
        order(candidates);
        addNumber(candidates,0);
        return solutions;
    }

    int solution_index;
    int target;
    int temp_sum;
    vector<vector<int>> solutions;
    vector<int> temp;
};