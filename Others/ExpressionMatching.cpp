#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    auto simplifyP(string p)
    {
        int index = 0;
        while(index+3<p.size())
        {
            if(p[index+1] == '*'&& p[index+3] == '*' && p[index] == p[index+2])
            {
                index+=2;
            }
            else
            break;
        }
        return p.substr(index,p.size()-index);
    }
public:
    bool isMatch(string s, string p) {
        p = simplifyP(p);
        int szS = 0;
        int szP = 0;
        bool matchIsCorrect = true;
        while(szS<s.size() && szP<p.size() && matchIsCorrect==true)
        {
            if(szP+1<p.size() && p[szP+1]=='*')
            {
                if (p[szP]==s[szS])
                {
                    bool oneMatchFound = false;
                    char letterToMatch = s[szS];
                    int i=0;
                    do
                    {
                        oneMatchFound |= isMatch(s.substr(szS+i,s.size()-szS-i),p.substr(szP+2,p.size()-szP-2));
                    } while (oneMatchFound == false && szS+i+1<=s.size() && s[szS+i++]==letterToMatch);
                    if(oneMatchFound == true) return true;
                    else return false;
                }
                else if(p[szP]=='.')
                {
                    bool oneMatchFound = false;
                    int i=0;
                    do
                    {
                        oneMatchFound |= isMatch(s.substr(szS+i,s.size()-szS-i),p.substr(szP+2,p.size()-szP-2));
                        i++;
                    } while (oneMatchFound == false && szS+i<=s.size());
                    if(oneMatchFound == true) return true;
                    else return false;
                }
                else
                {
                    szP+=2;
                }
            }
            else if (p[szP]=='.')
            {
                szP++;
                szS++;
            }
            else if(p[szP]==s[szS])
            {
                szP++;
                szS++;
            }
            else matchIsCorrect = false;
        }
        
        if(szS==s.size() && szP+1< p.size() && p[szP+1]=='*')
        {
            matchIsCorrect = isMatch(s.substr(szS,s.size()-szS),p.substr(szP+2,p.size()-szP-2));
        }
        else if(s.size()!=szS || p.size()!=szP) matchIsCorrect= false;
        return matchIsCorrect;
    }
};

int main()
{
    Solution solution;
    bool testResult = true;
    string s ="ab";
    string p =".*";
    testResult &= solution.isMatch(s,p);
    s ="ab";
    p =".*c";
    testResult &= !solution.isMatch(s,p);
    s ="aa";
    p ="a*";
    testResult &= solution.isMatch(s,p);
    s ="a";
    p ="ab*";
    testResult &= solution.isMatch(s,p);
    s ="aab";
    p ="c*a*b*c*";
    testResult &= solution.isMatch(s,p);
    s ="a";
    p ="ab*";
    testResult &= solution.isMatch(s,p);
    s ="aaaaaaaaaaaaab";
    p ="a*a*a*a*a*a*a*a*a*a*c";
    testResult &= solution.isMatch(s,p);
    cout<<testResult<<endl;
    return 0;
}