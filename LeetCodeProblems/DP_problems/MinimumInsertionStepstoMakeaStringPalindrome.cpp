#include <vector>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        dp.assign(n,vector<int>(n,-1));
        return compute(0,n-1,s);
    }
private:
    int compute(int start, int end, string& s)
    {
        if(dp[start][end]!=-1) return dp[start][end];
        else if(start>=end) return 0;
        else
        {
            if(s[start]==s[end]) return dp[start][end] = compute(start+1,end-1,s);
            else return dp[start][end]=1+min(compute(start+1,end,s),compute(start,end-1,s));
        }
    }

    vector<vector<int>> dp;
};