#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        temp_sum=0;
        this->target=target;
        sort(candidates.begin(),candidates.end());
        addNumber(candidates,0);
        return solutions;
    }
    
private:
    void addNumber(vector<int>& candidates, int index_start) {
        if(temp_sum==target)
        {
            if(s.find(temp)==s.end())
            {
                s.insert(temp);
                solutions.push_back(temp);
            }
        }
        else if(temp_sum<target)
        {
            for(int i=index_start;i<candidates.size();i++)
            {
                temp.push_back(candidates[i]);
                temp_sum+=candidates[i];
                addNumber(candidates, i+1);
                temp.pop_back();
                temp_sum-=candidates[i];
                while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
            }
        }
    }

    int target;
    int temp_sum;
    set<vector<int>> s;
    vector<vector<int>> solutions;
    vector<int> temp;
};