#include <queue>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int sz = source.size();
        int res = 0;
        vector<vector<int>> g(sz);
        vector<int> vis(sz,false);
        for(auto& e : allowedSwaps)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for(int i=0;i<sz;i++)
        {
            queue<int> q;
            if(!vis[i])
            {
                q.push(i);
                vis[i]=true;
            }
            vector<int> v;
            while(!q.empty())
            {
                int el = q.front();
                q.pop();
                v.push_back(el);
                for(auto& n : g[el])
                    if(!vis[n])
                    {
                        vis[n]=true;
                        q.push(n);
                    }
            }
            res+=v.size();
            map<int,int> m;
            for(auto& e : v) m[source[e]]++;
            for(auto& e : v)
            {
                if(m[target[e]]>0)
                {
                    res--;
                    m[target[e]]--;
                }
            }
        }
        return res;
    }
};