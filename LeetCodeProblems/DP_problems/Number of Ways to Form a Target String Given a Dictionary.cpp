#include <vector>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int sz = words[0].size();
        int wordNum = words.size();
        int mod = 1e9 + 7;
        vector<vector<int>> freq(sz,vector<int>(26,0));
        vector<long long> dp(target.size() + 1, 0);
        int res = 0;
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<wordNum;j++)
            {
                freq[i][words[j][i]-'a']++;
            }
        }
        dp[0] = 1;
        for (int j = 0; j < sz; j++) {
            for (int i = target.size(); i > 0; i--) {
                dp[i] = (dp[i] + dp[i-1] * freq[j][target[i-1] - 'a']) % mod;
            }
        }
        
        return dp[target.size()];
    }
};