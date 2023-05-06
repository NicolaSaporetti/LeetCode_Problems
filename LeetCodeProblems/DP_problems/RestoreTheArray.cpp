#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        mod = 1e9+7;
        dp.assign(s.size(), -1);
        return dfs(s, k, 0);
    }
private:
    int dfs(const string& s, long k, int i) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int ans = 0;
        long num = 0;
        for (int j = i; j < s.size(); j++) {
            num = num * 10 + s[j] - '0';
            if (num > k) break;
            ans = (ans + dfs(s, k, j + 1))%mod;
        }
        return dp[i] = ans;
    }
    vector<int> dp;
    int mod;
};