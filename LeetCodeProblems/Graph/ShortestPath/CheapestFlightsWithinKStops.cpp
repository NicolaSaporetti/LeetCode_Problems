#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto& e : flights) graph[e[0]].push_back({e[1],e[2]});
        stops.assign(n, numeric_limits<int>::max());
        pq.push({0, src, 0});
        return computeCheapestPath(graph,dst,k);
    }
private:
    int computeCheapestPath(vector<vector<pair<int,int>>>& graph, int dst, int k)
    {
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int dist = temp[0];
            int node = temp[1];
            int steps = temp[2];
            if (steps > stops[node] || steps > k + 1) continue;
            stops[node] = steps;
            if (node == dst) return dist;
            for (auto& [neighbor, price] : graph[node]) {
                pq.push({dist + price, neighbor, steps + 1});
            }
        }
        return -1;
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> stops;
};