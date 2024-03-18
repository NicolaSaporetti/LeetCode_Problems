#include <vector>
using namespace std;

class Solution {
public:
    int minimumTime(vector<int>& n1, vector<int>& n2, int x) {
        int sum1 = accumulate(begin(n1), end(n1), 0);
        int sum2 = accumulate(begin(n2), end(n2), 0);
        vector<int> dp(n1.size()+1);
        int n = n1.size();
        vector<int> ids(n1.size());
        iota(begin(ids), end(ids), 0);
        sort(begin(ids), end(ids), [&](int i, int j){ return n2[i] < n2[j]; });
        for (int i = 1; i <= n; ++i)
            for (int j = i; j > 0; --j)
                dp[j] = max(dp[j], dp[j - 1] + n2[ids[i - 1]] * j + n1[ids[i - 1]]);
        for (int t = 0; t <= n; ++t)
            if (sum1 + sum2 * t - dp[t] <= x)
                return t;
        return -1;
    }
};