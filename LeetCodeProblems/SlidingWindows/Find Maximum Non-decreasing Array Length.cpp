#include <vector>
using namespace std;

class Solution {
public:
    int findMaximumLength(vector<int>& A) {
        int n = A.size();
        vector<int> pre(n + 2), dp(n + 1);
        vector<long long> acc(n + 1);
        for (int i = 0; i < n; i ++) acc[i+1] = acc[i] + A[i];
        int i = 0;
        for (int j = 1; j <= n; j++) {
            i = max(i,pre[j]);
            dp[j] = dp[i] + 1;
            int ind = lower_bound(acc.begin(), acc.end(), 2 * acc[j] - acc[i]) - acc.begin();
            pre[ind] = j;
        }
        return dp[n];
    }
};