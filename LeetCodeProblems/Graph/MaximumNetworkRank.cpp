#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        sz = n;
        int result = 0;
        makeGraph(roads);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = graph[i].size()+graph[j].size();
                if(graph[i].find(j)!=graph[i].end()) sum--;
                result = max(sum,result);
            }
        }
        return result;
    }
private:
    void makeGraph(vector<vector<int>>& roads)
    {
        graph.resize(sz);
        for(int i=0;i<roads.size();i++)
        {
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
        }
    }
    
    int sz;
    vector<set<int>> graph;
};