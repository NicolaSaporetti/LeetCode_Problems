#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dst, int target) {
        adj.resize(n);
        for (auto& e: edges) {
            adj[e[0]].emplace_back(e[1], &e);
            adj[e[1]].emplace_back(e[0], &e);
        }
        vector<int> ds = computeShortestPathFromSource(n,src,dst,target);
        return ds[dst] == target ? edges : vector<vector<int>>{};
    }

private:
    vector<int> computeShortestPathFromSource(int n, int src, int dst, int target)
    {
        vector<int> dd = computeShortestPathFromDest(n,src,dst);
        vector<int> ds(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        ds[src] = 0;
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            for (auto& [v, e]: adj[node]) {
                if (e->at(2) == -1) e->at(2) = max(1, target - ds[node] - dd[v]);
                if (ds[v] > ds[node] + e->at(2)) {
                    ds[v] = ds[node] + e->at(2);
                    pq.push({ds[v], v});
                }
            }
        }
        return ds;
    }

    vector<int> computeShortestPathFromDest(int n, int src, int dst)
    {
        vector<int> dd(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, dst);
        dd[dst] = 0;
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            for (auto [v, e]: adj[node]) {
                int cost = e->at(2);
                if (cost == -1) cost = 1;
                if (dd[v] > dd[node] + cost)
                {
                    dd[v] = dd[node] + cost;
                    pq.push({dd[v], v});
                }
            }
        }
        return dd;
    }

    vector<vector<pair<int, vector<int>*>>> adj;
};