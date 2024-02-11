#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        vector<map<int,int>> v(26);
        int r = -1;
        char c = s[0];
        int d = 1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=c)
            {
                v[c-'a'][d]++;
                d=0;
            }
            d++;
            c = s[i];
        }
        v[c-'a'][d]++;
        for(int i=0;i<26;i++)
        {
            if(v[i].size()==0) continue;
            for(auto it = v[i].rbegin();it!=v[i].rend();it++)
            {
                if(it->second>=3) r=max(r,it->first);
                if(it->first>=3)
                {
                    v[i][it->first-2]+=(it->second*3);
                    v[i][it->first-1]+=(it->second*2);
                }
                else if(it->first>=2)
                {
                    v[i][it->first-1]+=(it->second*2);
                }
            }
        }
        return r;
    }
};