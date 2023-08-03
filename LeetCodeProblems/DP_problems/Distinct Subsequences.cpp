#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        rz = s.size();
        cz = t.size();
        dp.assign(rz+1,vector<int>(cz+1,-1));
        return h(0,0,s,t);
    }
private:
    int h(int sp, int tp, string& s, string& t)
    {
        if(dp[sp][tp]!=-1) return dp[sp][tp];
        else if(tp>=cz) return 1;
        else if(sp>=rz) return 0;
        {
            int val = 0;
            if(s[sp]==t[tp]) val+=h(sp+1,tp+1,s,t);
            val+=h(sp+1,tp,s,t);
            return dp[sp][tp]=val;
        }
    }

    vector<vector<int>> dp;
    int rz;
    int cz;
};