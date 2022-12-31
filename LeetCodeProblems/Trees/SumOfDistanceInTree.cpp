#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v = buildDirectGraphToLeafs(edges,n);
        childs.resize(n);
        countNodeBelow(0,v);
        int sum = computeInitialSum(0,v);
        result.resize(n);
        result[0]=sum;
        for(int i=0;i<v[0].size();i++)
        {
            compute(v[0][i],v,sum,n);
        }
        return result;
    }
private:
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

    int countNodeBelow(int node, vector<vector<int>>& graph)
    {
        int tot = 0;
        for(int i=0;i<graph[node].size();i++)
        {
            tot+=countNodeBelow(graph[node][i],graph);
        }
        childs[node]=tot;
        return tot+1;
    }

    int computeInitialSum(int node, vector<vector<int>>& graph)
    {
        int tot = 0;
        for(int i=0;i<graph[node].size();i++)
        {
            tot+=(1+childs[graph[node][i]]+computeInitialSum(graph[node][i],graph));
        }
        return tot;
    }

    void compute(int node, vector<vector<int>>& graph, int sum, int sz)
    {
        result[node] = sum+sz-childs[node]-1-(childs[node]+1);
        for(int i=0;i<graph[node].size();i++)
        {
            compute(graph[node][i],graph,result[node],sz);
        }
    }
    
    vector<int> childs;
    vector<int> result;
};