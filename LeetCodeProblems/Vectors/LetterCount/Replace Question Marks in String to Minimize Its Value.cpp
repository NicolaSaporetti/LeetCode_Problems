#include <vector>
using namespace std;

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> v(26,0);
        int sz = s.size();
        vector<vector<int>> after(sz+1,vector<int>(26,0));
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!='?') after[i][s[i]-'a']=1;
            for(int j=0;j<26;j++) after[i][j]+=after[i+1][j];
        }
        int r = 0;
        vector<int> pos;
        vector<char> v1;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='?')
            {
                pos.push_back(j);
                int c = -1;
                int val = INT_MAX;
                for(int i=0;i<26;i++)
                {
                    if(after[j+1][i]+v[i]<val)
                    {
                        val=after[j+1][i]+v[i];
                        c = i;
                    }
                }
                v1.push_back(c+'a');
                s[j]=(char)(c+'a');
            }
            v[s[j]-'a']++;
            //for(auto e: v) cout<<e<<" ";
            //cout<<endl;
        }
        sort(begin(v1),end(v1));
        for(int i=0;i<pos.size();i++)
            s[pos[i]]=v1[i];
        return s;
    }
};