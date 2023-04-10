#include <vector>
using namespace std;

class Kahn
{
public:
    Kahn(int nodes) : nodes(nodes)
    {
        color.assign(nodes, '0');
    }

    bool find_cycle(vector<vector<int>>& graph) {

        for (int v = 0; v < nodes; v++)
        {
            if (color[v] == '0' && dfs(v, graph)) return true;
        }
        return false;
    }

private:
    bool dfs(int v, vector<vector<int>>& graph) {
        color[v] = '1';
        for (int u : graph[v])
        {
            if (color[u] == '0')
            {
                if (dfs(u, graph))
                    return true;
            }
            else if (color[u] == '1')
            {
                return true;
            }
        }
        color[v] = '2';
        return false;
    }

vector<char> color;
int nodes;
};