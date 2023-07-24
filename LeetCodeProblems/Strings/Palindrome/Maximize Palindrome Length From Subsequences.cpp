#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> dp(sz1+sz2,vector<int>(sz1+sz2,0));
        string s = word1 + word2;
        int ans = 0;
        for (int j = 0; j < sz1+sz2; ++j) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 == j) ? 2 : dp[i+1][j-1] + 2;
                    if (i < sz1 and j >= sz1) ans = max(ans, dp[i][j]);
                }
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return ans;
    }
};