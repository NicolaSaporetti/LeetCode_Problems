#include <vector>
using namespace std;

class Solution {
public:
    int countSteppingNumbers(string l, string r) {
        memset(dp, -1, sizeof(dp));
        int L = solve(l, l.size(), 1, 1, 0);
        memset(dp, -1, sizeof(dp));
        int R = solve(r, r.size(), 1, 1, 0);
        return (R - L +isStepping(l) + mod)%mod;
    }
private:
    bool isStepping(string& num) {
        int prev = num[0] - '0';
        for(int i = 1; i < num.size(); i++) {
            int curr = num[i] - '0';
            if(abs(prev - curr) != 1)    return false;
            prev = curr;
        }
        return true;
    }
    int solve(string& num, int d, int tight, int leading, int prev) {
        if(d == 0)  return 1;
        if(dp[d][tight][leading][prev] != -1)   return dp[d][tight][leading][prev];
        int ub = tight ? num[num.size() - d] - '0' : 9;
        int ans = 0;
        if(leading) {
            for(int i = 0; i <= ub; i++)
                ans = (ans + solve(num, d - 1, tight & (i == ub), leading & (i == 0), i))%mod;
        }
        else {
            int n1 = prev - 1;
            int n2 = prev + 1;
            if(n1 <= ub and n1 >= 0)
                ans = (ans + solve(num, d - 1, tight & (n1 == ub), 0, n1))%mod;
            if(n2 <= ub and n2 >= 0)
                ans = (ans + solve(num, d - 1, tight & (n2 == ub), 0, n2))%mod;
        }
        return dp[d][tight][leading][prev] = ans;
    }
    int mod = 1e9 + 7;
    int dp[101][2][2][10];
};