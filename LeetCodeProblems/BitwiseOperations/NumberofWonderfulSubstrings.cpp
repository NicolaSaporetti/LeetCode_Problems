#include <vector>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int mask = 0;
        vector<int> dp(1025,0);
        dp[0]++;
        for (char &c: word) {
            mask ^= (1<<(c-'a'));
            ++dp[mask];
        }
        long long res = 0;
        for (int s = 0; s < (1<<10); ++s) {
            if (dp[s] == 0) continue;
            int sum = dp[s];
            for (int i = 0; i < 10; ++i) {
                sum += dp[s^(1<<i)];
            }
            res += (1LL*sum-1)*dp[s];
        }
        return res/2;
    }
};