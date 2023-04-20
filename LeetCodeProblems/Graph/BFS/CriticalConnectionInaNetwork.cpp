#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        time = 0;
		firstTime.resize(n), minTime.resize(n), visited.resize(n), graph.resize(n);
		for(auto& edge : connections) {
			int nodeA = edge[0], nodeB = edge[1];
			graph[nodeA].push_back(nodeB);
			graph[nodeB].push_back(nodeA);
		}
		dfs(0,-1);
		return ans;
	}
    
private:

	void dfs(int node, int parent) {
		firstTime[node] = minTime[node] = time++;
		visited[node] = true;

		for(auto& child : graph[node]) {
			if(child == parent)
				continue;

			if(!visited[child]) 
				dfs(child, node);

			minTime[node] = min(minTime[child], minTime[node]);

			if(firstTime[node] < minTime[child])
				ans.push_back({node, child});
		}
	}

	vector<vector<int>> ans;
	vector<vector<int>> graph;
	vector<int> firstTime;
	vector<int> minTime;
	vector<int> visited;
	int time;
};