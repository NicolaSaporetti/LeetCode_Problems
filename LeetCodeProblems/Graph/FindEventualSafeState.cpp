#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> sol;
        vector<set<int>> rgraph;
        vector<set<int>> ngraph;
        queue<int> myQ;
        rgraph.resize(graph.size());
        ngraph.resize(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            if(graph[i].empty())
            {
                sol.push_back(i);
                myQ.push(i);
            }
            else
            {
                for(int j=0;j<graph[i].size();j++)
                {
                    rgraph[graph[i][j]].insert(i);
                    ngraph[i].insert(graph[i][j]);
                }
            }
        }
        while(!myQ.empty()){
            int elem = myQ.front();
            myQ.pop();
            for(auto i=rgraph[elem].begin();i!=rgraph[elem].end();i++)
            {
                ngraph[*i].erase(elem);
                if(ngraph[*i].empty())
                {
                    sol.push_back(*i);
                    myQ.push(*i);
                }
            }
        }
        sort(sol.begin(),sol.end());
        return sol;
    }
};