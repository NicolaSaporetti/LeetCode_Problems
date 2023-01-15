#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int tot = 0;
        vector<vector<int>> graph = buildDirectGraphToLeafs(edges, n);
        search(0,graph, hasApple);
        for(auto e : hasApple) if(e) tot+=2;
        return max(0,tot-2);
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

    void search(int node, vector<vector<int>>& graph, vector<bool>& hasApple)
    {
        for(int i=0;i<graph[node].size();i++)
        {
            search(graph[node][i],graph,hasApple);
            hasApple[node] = hasApple[node] || hasApple[graph[node][i]];
        }
    }
};