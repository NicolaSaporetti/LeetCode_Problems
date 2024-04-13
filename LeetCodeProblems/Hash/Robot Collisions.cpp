#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int sz = positions.size();
        vector<int> r(sz,0);
        vector<pair<int,int>> v(sz);
        for(int i=0;i<sz;i++) v[i]={positions[i],i};
        sort(begin(v),end(v));
        stack<pair<int,int>> s;
        for(int i=0;i<sz;i++)
        {
            int pos = v[i].second;
            if(directions[pos]=='R') s.push({healths[pos],pos});
            else
            {
                int h = healths[pos];
                while(!s.empty() && h>0)
                {
                    if(s.top().first>h)
                    {
                        s.top().first--;
                        h=0;
                    }
                    else if(s.top().first==h)
                    {
                        s.pop();
                        h=0;
                    }
                    else
                    {
                        h--;
                        s.pop();
                    }
                }
                if(h>0) r[pos]=h;
            }
        }
        while(!s.empty())
        {
            r[s.top().second]=s.top().first;
            s.pop();
        }
        int pos = 0;
        for(int i=0;i<sz;i++) if(r[i]!=0) r[pos++]=r[i];
        r.resize(pos);
        return r;
    }
};