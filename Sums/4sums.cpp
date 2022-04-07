#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    private:
    void order(vector<int>& vec)
    {
        for(int i=0; i< vec.size()-1; i++)
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

    bool is_duplicate(vector<vector<int>>& solutions, vector<int>& temp)
    {
        bool found = false;
        for(int i=0; i< solutions.size() && !found; i++)
        {
            if(solutions[i][0]==temp[0] &&
               solutions[i][1]==temp[1] &&
               solutions[i][2]==temp[2] &&
               solutions[i][3]==temp[3])
            {
                found = true;
            }
        }
        return found;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> solutions;
        order(nums);
        int result = 0;
        cout<<nums.size()<<endl;
        for(int i=0; i< nums.size()-3 && nums.size()>3; i++)
        {
            for(int t=nums.size()-1; t>2; t--)
            {
                int j = i+1;
                int k = t-1;
                while(j<k)
                {
                    long long sum = 0;
                    sum+= nums[i];
                    sum+= nums[j];
                    sum+= nums[k];
                    sum+= nums[t];
                    if (sum == target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[t]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[i]);
                        if(!is_duplicate(solutions, temp))
                        {
                            solutions.push_back(temp);
                        }
                        j++;
                    }
                    else{
                        if(sum-target >0)
                        {
                            k--;
                        }
                        else{
                            j++;
                        }
                    }
                }
            }
        }
        return solutions;
    }
};

int main()
{
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    Solution solution;
    vector<vector<int>> final = solution.fourSum(nums, 8);
    for(int i=0;i<final.size();i++)
    {
        for(int j=0;j<final[i].size();j++)
        {
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}