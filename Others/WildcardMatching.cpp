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
        while(index+1<p.size())
        {
            if(p[index+1] == '*' && p[index] == '*')
            {
                index++;
            }
            else
            break;
        }
        return p.substr(index,p.size()-index);
    }
    bool checkFinalPart(string s, string p)
    {
        int pureLetterNum = 0;
        bool loopStay = true;
        for(int i=p.size()-1; i>=0 && loopStay==true; i--)
        {
            if(p[i]!='*' && p[i]!='?')
            {
                pureLetterNum++;
            }
            else{
                loopStay=false;
            }
        }
        loopStay= true;
        for(int i=0;i<pureLetterNum && i<s.size() && loopStay==true;i++)
        {
            if(p[p.size()-1-i] != s[s.size()-1-i]) loopStay = false;
        }
        return loopStay;
    }
public:
    bool isMatch(string s, string p) {
        cout<<s<<endl;
        cout<<p<<endl;
        p = simplifyP(p);
        int szS = 0;
        int szP = 0;
        bool matchIsCorrect = checkFinalPart(s,p);
        while(szS<s.size() && szP<p.size() && matchIsCorrect==true)
        {
            if(p[szP]=='*')
            {
                bool oneMatchFound = false;
                int i=s.size()-1-szS;
                do
                {
                    oneMatchFound |= isMatch(s.substr(szS+i,s.size()-szS-i),p.substr(szP+1,p.size()-szP-1));
                } while (oneMatchFound == false && i-->0);
                if(oneMatchFound == true) return true;
                else return false;
                szP++;
            }
            else if (p[szP]=='?')
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
        if(szS==s.size() && p[szP]=='*')
        {
            matchIsCorrect = isMatch(s.substr(szS,s.size()-szS),p.substr(szP+1,p.size()-szP-1));
        }
        else
        {
            if(s.size()!=szS || p.size()!=szP) 
            {
                matchIsCorrect= false;
            }
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
    /*s ="ab";
    p ="?*c";
    testResult &= !solution.isMatch(s,p);
    s ="aa";
    p ="a*";
    testResult &= solution.isMatch(s,p);
    s ="a";
    p ="ab*";
    testResult &= !solution.isMatch(s,p);
    s ="aab";
    p ="c*a*b*c*";
    testResult &= !solution.isMatch(s,p);
    s ="a";
    p ="ab*";
    testResult &= !solution.isMatch(s,p);
    s ="aaaaaaaaaaaaab";
    p ="a*a*a*a*a*a*a*a*a*a*c";
    testResult &= solution.isMatch(s,p);*/
    s="bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab";
    p="b*b*ab**ba*b**b***bba";
    cout<<solution.isMatch(s,p)<<endl;
    s ="aa";
    p ="*";
    cout<<solution.isMatch(s,p)<<endl;
    return 0;
}