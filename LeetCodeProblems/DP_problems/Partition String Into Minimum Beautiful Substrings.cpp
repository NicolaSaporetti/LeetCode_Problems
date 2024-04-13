#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        sz = s.size();
        dp.assign(sz,vector<int>(sz,-2));
        int v = 1;
        for(int i=0;i<7;i++)
        {
            se.insert(v);
            v*=5;
        }
        return dfs(0,0,0,s);
    }
private:
    int dfs(int start, int cur, int val,string& s)
    {
        if(s[start]=='0') return -1;
        else if(start==sz && cur==sz) return 0;
        else if(start<sz && cur==sz) return -1;
        else if(dp[start][cur]!=-2) return dp[start][cur];
        {
            val*=2;
            val+=s[cur]-'0';
            int v1 = -1;
            if(se.count(val)>0) v1 = dfs(cur+1,cur+1,0,s);
            if(v1!=-1) v1++;
            int v2 = dfs(start,cur+1,val,s);
            if(v1==-1 && v2 == -1) return dp[start][cur]=-1;
            else if(v1==-1) return dp[start][cur]=v2;
            else if(v2==-1) return dp[start][cur]=v1;
            else return dp[start][cur]=min(v1,v2);
        }
    }

    vector<vector<int>> dp;
    int sz;
    set<int> se;
};