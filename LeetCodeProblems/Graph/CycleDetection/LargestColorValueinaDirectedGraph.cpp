#include <vector>
#include <queue>
#include "Kahn.hpp"
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        setupGraph(edges);
        Kahn kahn(nodes);
        if(kahn.find_cycle(graph)) return -1;
        else
        {
            return findLargestPath(colors);
        }
    }
private:
    void setupGraph(vector<vector<int>>& edges)
    {
        nodes = 0;
        for(auto& e : edges) nodes = max(nodes, max(e[0],e[1]));
        nodes++;
        graph.resize(nodes);
        InEdges.resize(nodes);
        colorByNodes.assign(nodes,vector<int>(26,0));
        for(auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            InEdges[e[1]]++;
        }
    }

    int findLargestPath(string colors)
    {
        int res = 1;
        queue<int> q;
        for(int i=0;i<nodes;i++)
        {
            if(InEdges[i]==0) q.push(i);
            colorByNodes[i][colors[i]-'a']=1;
        }
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            for(int i=0;i<graph[el].size();i++)
            {
                int newEl = graph[el][i];
                InEdges[newEl]--;
                if(InEdges[newEl]==0) q.push(newEl);
                for(int i=0;i<26;i++)
                {
                    int letter = (colors[newEl]-'a'==i)? 1 : 0;
                    colorByNodes[newEl][i]=max(colorByNodes[newEl][i],colorByNodes[el][i]+letter);
                    res = max(res,colorByNodes[newEl][i]);
                }
            }
        }
        return res;
    }

    vector<vector<int>> graph;
    vector<int> InEdges;
    vector<vector<int>> colorByNodes;
    int nodes;
};