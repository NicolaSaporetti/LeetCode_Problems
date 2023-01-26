#include <vector>
using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        buildGraph(edges,values.size());
        temp.push_back(0);
        val = values[0];
        res = val;
        traverse(maxTime,values);
        return res;
    }
private:
    void buildGraph(vector<vector<int>>& edges, int sz)
    {
        graph.resize(sz);
        for(auto& e : edges)
        {
            graph[e[0]].push_back({e[1],e[2]});
            graph[e[1]].push_back({e[0],e[2]});
        }
    }
    
    void traverse(int timeLeft, vector<int>& values)
    {
        int node = temp.back();
        for(int i=0;i<graph[node].size();i++)
        {
            int newNode = graph[node][i].first;
            int priceEdge = graph[node][i].second;
            if(timeLeft-priceEdge<0) continue;
            int priceGain = 0;
            if(find(begin(temp),end(temp),newNode)==temp.end()) priceGain = values[newNode];
            
            val+=priceGain;
            if(newNode==0) res = max(val,res);
            temp.push_back(newNode);
            traverse(timeLeft-priceEdge,values);
            temp.pop_back();
            val-=priceGain;
        }
    }
    
    vector<int> temp;
    int val;
    vector<vector<pair<int,int>>> graph;
    int res;
};