#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        for(int i=0;i<s1.size();i++) if(s1[i]!=s2[i]) v.push_back(i);
        int sz = v.size();
        if(sz%2==1) return -1;
        dp.assign(sz,vector<int>(sz,-1));
        vector<int> changes;
        return helper(0,v.size()-1,x);
    }
private:
    int helper(int s,int e,int x){
        if(s>e) return 0;
        else if(dp[s][e]!=-1) return dp[s][e];
        else if(e-s==1) return dp[s][e]=min(v[e]-v[s],x);
        else
        {
            int r = helper(s+1,e-1,x)+min(x,v[e]-v[s]);
            for(int i=s+1;i<e;i+=2)
            {
                r = min(helper(s,i,x)+helper(i+1,e,x),r);
            }
            return dp[s][e]=r;
        }
    }
    
    vector<int> v;
    vector<vector<int>> dp;
};