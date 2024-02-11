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
        vector<long long> cost;
        for(auto e : values) cost.push_back(e);
        vector<int> in (n,0);
        queue<int> q;
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i]!=-1) in[v[i]]++;
            if(in[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            if(val[el]!=0)
            {
                res+=max(cost[el], val[el]);
                val[el]=min(val[el],cost[el]);
            }
            else val[el]=cost[el];
            
            if(v[el]!=-1)
            {
                val[v[el]]+=val[el];
                in[v[el]]--;
                if(in[v[el]]==0) q.push(v[el]);
            }
        }
        return res;
    }
};