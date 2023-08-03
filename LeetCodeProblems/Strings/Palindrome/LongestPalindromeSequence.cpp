#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz+1,vector<int>(sz+1,0));
        for (int j = 1; j <= sz; ++j) 
            for (auto i = 0; i + j <= s.size(); ++i)
                dp[i][i + j] = (s[i] == s[i + j - 1]) ? dp[i + 1][i + j - 1] + (j == 1 ? 1 : 2) : max(dp[i][i + j - 1],  dp[i + 1][i + j]);
        return dp[0][sz];
    }
};