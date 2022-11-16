#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        sz1=s1.size();
        sz2=s2.size();
        dp.assign(sz1+1,vector<int>(sz2+1,-1));
        if(sz1+sz2!=s3.size()) return false;
        return areInterleaved(s1,s2,s3,0,0);
    }
    
private:    
    bool areInterleaved(string& s1, string& s2, string& s3, int i1, int i2)
    {
        bool res = false;
        if(dp[i1][i2]!=-1) res = dp[i1][i2];
        else
        {
            if(i1+i2>=sz1+sz2) res = true;
            else
            {
                if(sz1 && s1[i1]==s3[i1+i2]) res = areInterleaved(s1,s2,s3,i1+1,i2);
                if(!res && i2<sz2 && s2[i2]==s3[i1+i2]) res = areInterleaved(s1,s2,s3,i1,i2+1);
            }
            dp[i1][i2]=res;
        }
        return res;
    }
    
    vector<vector<int>> dp;
    int sz1;
    int sz2;
};