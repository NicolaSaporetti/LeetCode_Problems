#include <vector>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int sz = s.size();
        vector<int> dp(sz+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<sz;i++)
        {
            for(auto e : dictionary)
            {
                if(i+e.size()>sz) continue;
                if(s.substr(i,e.size())==e) dp[i+e.size()]=min(dp[i+e.size()],dp[i]);
            }
            dp[i+1]=min(dp[i+1],dp[i]+1);
        }
        return dp[sz];

    }
};