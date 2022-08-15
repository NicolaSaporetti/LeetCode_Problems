#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<int,vector<int>> myM;
    vector<int> result;
    int sz;
    
    void computeGreatestFrequencyElements(int k)
    {
        for(auto it=myM.rbegin();it!=myM.rend() && k>0;it++)
        {
            for(int j=0;j<it->second.size();j++)
            {
                result.push_back(it->second[j]);
                k--;
            }
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sz = nums.size();
        sort(nums.begin(),nums.end());
        int j=1;
        for(int i=0;i<sz;i+=j)
        {
            j=1;
            for(;j+i<sz && nums[i]==nums[i+j];j++);
            auto it = myM.find(j);
            if(it!=myM.end())
            {
                it->second.push_back(nums[i]);
            }
            else
            {
                vector<int> temp(1,nums[i]);
                myM.insert(make_pair(j,temp));
            }
        }
        computeGreatestFrequencyElements(k);
        return result;
    }
};