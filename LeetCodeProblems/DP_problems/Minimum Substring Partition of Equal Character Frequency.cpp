#include <vector>
#include "Dijkstra.cpp"
using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        dp.assign(s.size(),vector<int>(s.size(),-1));
        c.assign(s.size()+1,vector<int>(26,0));
        sz = s.size();
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<26;j++) c[i+1][j]=c[i][j];
            c[i+1][s[i]-'a']++;
        }
        return dfs(0,0);
    }
private:
    int dfs(int s, int e)
    {
        if(e==sz-1)
        {
            int v = 0;
            bool isV = true;
            for(int i=0;i<26 && isV;i++)
            {
                if(c[e+1][i]-c[s][i]==0) continue;
                else if(v==0) v=c[e+1][i]-c[s][i];
                else if(c[e+1][i]-c[s][i]!=v) isV = false;
            }
            return (isV) ? 1 : 1001;
        }
        else if(dp[s][e]!=-1) return dp[s][e];
        else
        {
            int v = 0;
            bool isV = true;
            for(int i=0;i<26 && isV;i++)
            {
                if(c[e+1][i]-c[s][i]==0) continue;
                else if(v==0) v=c[e+1][i]-c[s][i];
                else if(c[e+1][i]-c[s][i]!=v) isV = false;
            }
            int v1 = dfs(s,e+1);
            int v2 = (isV)? dfs(e+1,e+1)+1 : 1001;
            return dp[s][e]=min(v1,v2);
        }
    }
    
    vector<vector<int>> dp;
    vector<vector<int>> c;
    int sz;
};