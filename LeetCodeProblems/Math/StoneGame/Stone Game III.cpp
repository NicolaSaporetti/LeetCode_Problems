#include <vector>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        n = stoneValue.size();
        pref.assign(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i+1] = pref[i] + stoneValue[i];
        dp.assign(n + 1, vector<int>(2, -1));
        int alice = help(0, true);
        if (alice > 0) return "Alice";
        else if (alice < 0) return "Bob";
        return "Tie";
    }

private:
    int help(int idx, bool turn)
    {
        if (idx >= n) return 0;

        if (dp[idx][turn] != -1) return dp[idx][turn];

        if (turn)
        {
            int ans = INT_MIN;
            for (int x = 1; x <= 3; x++)
                if (idx + x - 1 < n)
                    ans = max(ans, pref[idx+x] - pref[idx] + help(idx + x, false));
            return dp[idx][turn] = ans;
        }
        else
        {
            int ans = INT_MAX;
            for (int x = 1; x <= 3; x++)
                if (idx + x - 1 < n)
                    ans = min(ans, -pref[idx+x] + pref[idx] + help(idx + x, true));

            return dp[idx][turn] = ans;
        }
    }

    vector<int> pref;
    vector<vector<int>> dp;
    int n;
};