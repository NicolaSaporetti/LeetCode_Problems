#include <vector>
using namespace std;

class TopologicalSort
{
public:
    TopologicalSort(int nodes) : nodes(nodes)
    {
        visited.assign(nodes, false);
    }

    vector<int> topological_sort(vector<vector<int>>& graph) {
        vector<int> ans;
        for (int i = 0; i < nodes; ++i)
        {
            if (!visited[i])
                dfs(i, graph, ans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(int v, vector<vector<int>>& graph, vector<int>& ans)
    {
        visited[v] = true;
        for (int u : graph[v]) {
            if (!visited[u])
                dfs(u, graph, ans);
        }
        ans.push_back(v);
    }

vector<bool> visited;
int nodes;
};