#include <vector>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        sz = s.size();
        dp.assign(sz,vector<int>(sz,-1));
        return compute(0,0,s);
    }
private:
    bool compute(int pos, int open, string& s)
    {
        if(pos>=sz) return (open==0);
        else if(open<0) return false;
        else if(dp[pos][open]!=-1) return dp[pos][open];
        else
        {
            bool sol = false;
            if(s[pos]=='(') sol = compute(pos+1,open+1,s);
            else if(s[pos]==')') sol = compute(pos+1,open-1,s);
            else sol = compute(pos+1,open+1,s)||compute(pos+1,open,s)||compute(pos+1,open-1,s);
            return dp[pos][open]=sol;
        }
    }

    int sz;
    vector<vector<int>> dp;
};