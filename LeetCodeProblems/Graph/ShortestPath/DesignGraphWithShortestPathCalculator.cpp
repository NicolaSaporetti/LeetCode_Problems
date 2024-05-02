#include <vector>
#include "Dijkstra.cpp"
using namespace std;

class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        sz = n;
        g.resize(n);
        for(int i=0;i<edges.size();i++) g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2, sz, g);
    }
private:
    int sz;
    vector<vector<vector<int>>> g;
};