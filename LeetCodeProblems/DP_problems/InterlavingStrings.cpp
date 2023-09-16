#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        dp.assign(s1.size()+1,vector<int>(s2.size()+1,-1));
        return compute(0,0,s1,s2,s3);
    }
private:
    bool compute(int n1, int n2, string& s1, string& s2, string& s3)
    {
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        else if(n1+n2>=s3.size()) return true;
        else
        {
            bool match1 = (n1<s1.size() && s1[n1]==s3[n1+n2])? compute(n1+1,n2,s1,s2,s3) : false;
            bool match2 = (n2<s2.size() && s2[n2]==s3[n1+n2])? compute(n1,n2+1,s1,s2,s3) : false;
            return dp[n1][n2] = match1 | match2;
        }
    }
    vector<vector<int>> dp;
};