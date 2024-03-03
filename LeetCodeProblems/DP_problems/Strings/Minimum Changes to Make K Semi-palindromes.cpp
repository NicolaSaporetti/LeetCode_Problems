#include <vector>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        sz = s.size();
        v.assign(sz,vector<int>(sz,-1));
        dp.assign(sz,vector<vector<int>>(sz,vector<int>(k+1,-1)));
        return helper(0,0,s,k);
    }
private:
    int helper(int start, int end, string& s, int k)
    {
        if((k==0 && end<sz) || (k>0 && end>=sz)) return 1e9;
        else if(k==0 && end>=sz) return 0;
        else if(dp[start][end][k]!=-1) return dp[start][end][k];
        else
        {
            int v1 = compute(s,start,end)+helper(end+1,end+1,s,k-1);
            int v2 = helper(start,end+1,s,k);
            return dp[start][end][k]=min(v1,v2);
        }
    }

    int compute(string& s, int start, int end)
    {
        int len = end-start+1;
        if(v[start][end]!=-1) return v[start][end];
        else if(len==1) return v[start][end] = 1e9;
        else
        {
            int res = 1e9;
            for(int i=1;i<=len/2;i++)
            {
                if(len%i!=0) continue;
                res = min(res,palindromeCost(s,start,end,i));
            }
            return v[start][end]=res;
        }
    }
    int palindromeCost(string& s, int start, int end, int step)
    {
        int cost = 0;
        int szS = end-start+1;
        for(int j=0;j<step;j++)
        {
            for(int i=0;i<szS/2;i+=step)
            {
                if(s[start+i+j]!=s[start+szS-step+j-i]) cost++;
            }
        }
        return cost;
    }

    vector<vector<vector<int>>> dp;
    vector<vector<int>> v;
    int sz;
};