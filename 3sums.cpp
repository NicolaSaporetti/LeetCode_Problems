#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
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

    void arrange_pos_neg(vector<int>& positives, vector<int>& negatives, vector<int>& nums)
    {
        int i=0;
        while(i< nums.size() && nums[i]<0)
        {
            if(negatives.size()>=2)
            {
                if((nums[i] == nums[i-1]) && (nums[i-1] == nums[i-2]))
                {
                }
                else{
                    negatives.push_back(nums[i]);
                }
            }
            else{
                negatives.push_back(nums[i]);
            }
            i++;
        }

        while(i< nums.size() && nums[i]==0)
        {
            if(positives.size()<=2)
            {
                positives.push_back(nums[i]);
            }
            i++;
        }

        while(i< nums.size())
        {
            if(positives.size()>=2)
            {
                if((nums[i] == nums[i-1]) && (nums[i-1] == nums[i-2]))
                {
                }
                else{
                    positives.push_back(nums[i]);
                }
            }
            else{
                positives.push_back(nums[i]);
            }
            i++;
        }
    }

    void add_solution(int i, int j, int k, vector<vector<int>>& solutions)
    {
        vector<int> single_triple;
        single_triple.push_back(i);
        single_triple.push_back(j);
        single_triple.push_back(k);
        order(single_triple);
        if(!is_duplicate(solutions, single_triple))
        {
            solutions.push_back(single_triple);
        }
    }

    bool is_duplicate(vector<vector<int>>& solutions, vector<int>& triple)
    {
        bool found = false;
        for(int i=0; i< solutions.size() && !found; i++)
        {
            if(solutions[i][0]==triple[0] &&
               solutions[i][1]==triple[1] &&
               solutions[i][2]==triple[2])
            {
                found = true;
            }
        }
        return found;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solutions;
        vector<int> positives;
        vector<int> negatives;
        order(nums);
        arrange_pos_neg(positives, negatives, nums);
        for(int i=0; i< positives.size(); i++)
        {
            int k = negatives.size()-1;
            for(int j=i+1; j< positives.size() && k>=0; j++)
            {
                while(k>=0 && positives[i]+positives[j]+negatives[k]>=0)
                {
                    if(positives[i]+positives[j]+negatives[k]==0)
                    {
                        add_solution(positives[i], positives[j], negatives[k], solutions);
                    }
                    k--;
                }
            }
        }
        for(int i=negatives.size()-1; i>=0; i--)
        {
            int k = 0;
            for(int j=i-1; j>=0 && k< positives.size(); j--)
            {
                while(k< positives.size() && negatives[i]+negatives[j]+positives[k]<=0)
                {
                    if(negatives[i]+negatives[j]+positives[k]==0)
                    {
                        add_solution(negatives[i], negatives[j], positives[k], solutions);
                    }
                    k++;
                }
            }
        }
        if(positives.size()>=3 && (positives[0]+positives[1]+positives[2]==0))
        {
                add_solution(positives[0], positives[1], positives[2], solutions);
        }
        return solutions;
    }
};

int main()
{
    vector<int> nums;
    vector<vector<int>> result;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    Solution solution;
    solution.threeSum(nums);
    for(int i=0; i< result.size(); i++)
    {
        for(int j=0; j< result[i].size(); j++)
        {
            cout<<result[i][j]<<endl;
        }
    }
    return 0;
}