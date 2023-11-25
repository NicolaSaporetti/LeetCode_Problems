#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> buildDirectGraphToLeafs(vector<vector<int>>& edges, int sz)
{
    vector<set<int>> m(sz);
    vector<vector<int>> res(sz);
    for(auto e : edges)
    {
        m[e[0]].insert(e[1]);
        m[e[1]].insert(e[0]);
    }
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int el = q.front();
        q.pop();
        for(auto e : m[el])
        {
            m[e].erase(el);
            q.push(e);
        }
    }
    for(int i=0;i<sz;i++)
        for(auto e : m[i]) res[i].push_back(e);
    return res;
}

vector<int> buildDirectGraphToRoot(vector<vector<int>>& graphRootToLeaf, int sz)
{
    vector<int> res(sz,-1);
    for(int i=0;i<sz;i++)
        for(int j=0;j<graphRootToLeaf[i].size();j++) res[graphRootToLeaf[i][j]]=i;
    return res;
}

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<vector<int>> outg = buildDirectGraphToLeafs(edges,n);
        vector<int> v = buildDirectGraphToRoot(outg,n);
        vector<long long> val(n,0);
        vector<int> out(n,0);
        queue<int> q;
        long long res = 0;
        for(int i=0;i<n;i++) val[i]=values[i];
        for(auto& e : v) if(e!=-1) out[e]++;
        for(int i=0;i<n;i++) if(out[i]==0) q.push(i);
        while(!q.empty())
        {
            int el = q.front();
            int value = val[el];
            long long t = 0;
            res+=val[el];
            for(auto& e : outg[el]) t+=val[e];
            if(t>0) val[el]=min(val[el],t);
            int rad = v[el];
            if(rad==-1) break;
            q.pop();
            out[rad]--;
            if(out[rad]==0) q.push(rad);
        }
        return res-val[0];
    }
};