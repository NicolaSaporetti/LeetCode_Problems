#include <vector>
using namespace std;

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        minv = min_sum;
        maxv = max_sum;
        memset(dp, -1, sizeof(dp));
        int L = solve(num1, 0, true, 0);
        memset(dp, -1, sizeof(dp));
        int R = solve(num2, 0, true, 0);
        return (R - L + isValid(num1)+mod)%mod;
    }
private:
    bool isValid(string& num) {
        int s = 0;
        for(auto e : num) s+=(e-'0');
        return (s<=maxv && s>=minv);
    }
    int solve(string& num, int pos, int tight, int sum) {
        if(sum>maxv) return 0;
        if(pos>=num.size()) return (sum>=minv);
        else if(dp[sum][tight][pos] != -1) return dp[sum][tight][pos];
        else
        {
            int ub = tight ? num[pos] - '0' : 9;
            int ans = 0;
            for(int i = 0; i <= ub; i++)
                ans = (ans + solve(num, pos+1, tight & (i == ub), sum+i))%mod;
            return dp[sum][tight][pos] = ans;
        }
    }
    int mod = 1e9 + 7;
    int dp[401][2][23];
    int minv;
    int maxv;
};