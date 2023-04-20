#include <vector>
using namespace std;

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        rz = mat.size();
        cz = mat[0].size();
        res = INT_MAX;
        dp.assign(rz,vector<bool>(5000,false));
        compute(0,0,mat,target);
        return res;
    }
private:
    void compute(int r,int t, vector<vector<int>>& mat, int target)
    {
        for(int i=0;i<cz;i++)
        {
            t+=mat[r][i];
            if(!dp[r][t])
            {
                dp[r][t]=true;
                if(r==rz-1) res=min(res,abs(t-target));
                else
                {
                    compute(r+1,t,mat,target);
                }
            }
            t-=mat[r][i];
        }
    }
    
    int res;
    int rz;
    int cz;
    vector<vector<bool>> dp;
};