#include <vector>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int K) {
        vector<vector<int>> f(n+1,vector<int>(K+1,0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++ i)
        {
            long long s = 0;
            for (int j = 0; j <= K; ++ j)
            {
                s += f[i - 1][j];
                if (j >= i) s -= f[i - 1][j - i];
                f[i][j] = s % mod; 
            }
        }
        return f[n][K];
    }

private:
    const int mod = 1e9 + 7;
};