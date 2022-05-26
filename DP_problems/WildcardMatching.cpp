#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void simplifyP(string& p)
    {
        int newIndex = 0;
        for(int i= 0;i<p.size();i++)
        {
            p[newIndex++] = p[i];
            if(p[i] == '*')
            {
                while(i+1<p.size() && p[i]==p[i+1]) i++;
            }
        }
        p.resize(newIndex);
    }
    
    bool checkFinalPart(string& s, string& p)
    {
        bool finalPartIsCompatible = true;
        int i =0;
        int j =0;
        for(i=p.size()-1, j = s.size()-1; i>=0 && j>=0; i--, j--)
        {
            if(p[i]=='*' || p[i]=='?') break;
            else{
                if(p[i]!=s[j])
                {
                    finalPartIsCompatible = false;
                    break;
                }
            }
        }
        p.resize(i+1);
        s.resize(j+1);
        return finalPartIsCompatible;
    }
    
    bool checkSubstringMatch(string& s, string& p)
    {
        string sub;
        for(int i=0;i<p.size();i++)
        {
            int start = i;
            while(i<p.size() && p[i]!='*' && p[i]!='?') i++;
            if(start!=i)
            {
                sub=p.substr(start,i-start);
                size_t found = s.find(sub);
                if (found==string::npos) return false;
            }
        }
        return true;
    }
public:
    bool isMatch(string s, string p) {
        simplifyP(p);
        bool matchIsCorrect =  checkFinalPart(s,p) && checkSubstringMatch(s,p);
        if(matchIsCorrect)
        {
            int n = s.length();
            int m = p.length();
            bool dp[n+1][m+1];

            dp[0][0]=true;

            for(int i=1;i<=n;i++)
            {
                dp[i][0] = false;
            }

            for(int j=1;j<=m;j++)
            {
                if(p[j-1]=='*')
                {
                    dp[0][j] = dp[0][j-1];
                }
                else
                {    
                    dp[0][j] = false;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if((s[i-1]==p[j-1]) || (p[j-1]=='?'))
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*')
                    {
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
            return dp[n][m];
        }
        return matchIsCorrect;
    }
};

int main()
{
    Solution solution;
    string s ="ab";
    string p ="?*";
    cout<<solution.isMatch(s,p)<<endl;
    return 0;
}