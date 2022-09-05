#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int wz=nums[0].size();
        sol.assign(queries.size(),0);
        for(int i=0;i<queries.size();i++)
        {
            map<string,vector<int>> temp;
            for(int j=0;j<nums.size();j++)
            {
                temp[nums[j].substr(wz-queries[i][1])].push_back(j);
            }
            sol[i]=get_value(temp,queries[i][0]-1);
        }
        return sol;
    }
private:
    int get_value(map<string,vector<int>>& temp, int num)
    {
        int k=0;
        for(auto it=temp.begin();it!=temp.end();it++)
        {
            for(int y=0;y<it->second.size();y++,k++)
                if(k==num)
                {
                    return it->second[y];
                }
        }
        return 0;
    }
    
    vector<int> sol;
};