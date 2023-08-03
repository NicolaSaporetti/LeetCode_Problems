#include <vector>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int sz = s.size();
        string res;
        for(int i=0;i<sz;i++)
        {
            vector<int> l(26,0);
            vector<int> u(26,0);
            for(int j=i;j<sz;j++)
            {
                if(s[j]>='a' && s[j]<='z') l[s[j]-'a']++;
                else u[s[j]-'A']++;
                if(isNice(l,u))
                {
                    if(j-i+1>res.size()) res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
private:
    bool isNice(vector<int>& l, vector<int>& u)
    {
        for(int i=0;i<26;i++)
        {
            if((l[i]>0 && u[i]<=0) || (l[i]<=0 && u[i]>0)) return false;
        }
        return true;
    }
};