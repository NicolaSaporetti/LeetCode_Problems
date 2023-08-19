#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        dp[0]=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='0') dp[i+1]=dp[i];
            if(i>0 && (s[i-1]-'0'==1 || (s[i-1]-'0'==2 && s[i]-'0'<7))) dp[i+1]+=dp[i-1];
        }
        return dp[s.size()];
    }
};