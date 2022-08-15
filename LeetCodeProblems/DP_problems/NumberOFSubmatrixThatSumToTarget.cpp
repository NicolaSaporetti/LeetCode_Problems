#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        row_sz = matrix.size();
        col_sz = matrix[0].size();
        compute2DmatrixSum(matrix);
        int res = 0;
        vector<int>v(col_sz,0);
        for(int i=0;i<row_sz;i++)
        {
            for(int j=i;j<row_sz;j++)
            {
                for(int k=0;k<col_sz;k++)
                {
                    v[k]=matrix[j][k];
                    if(i>0) v[k]-=matrix[i-1][k];
                }
                res+=solve(v,target);
            }
        }
        return res;
    }
    
private:
    int row_sz;
    int col_sz;
    
    void compute2DmatrixSum(vector<vector<int>>& matrix)
    {
        for(int i=1;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                matrix[i][j]+=matrix[i-1][j];
            }
        }
    }
    
    int solve(vector<int>&nums,int target)
    {
        unordered_map<int,int> mp;
        int cs=0;
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            cs+=nums[i];
            if(cs==target)
            {
                ans++; 
            }
            if(mp.find(cs-target)!=mp.end())
            {
                ans+=mp[cs-target];
            }
            mp[cs]++;
        }
        return ans;
    }
};