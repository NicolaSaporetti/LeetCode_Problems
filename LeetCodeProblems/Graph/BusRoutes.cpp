#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        res = 0;
        setupGraph(routes);
        if(source==target) return res;
        addBusSetFromCorrispondingBusStop(routes, source);
        while(!busLines.empty())
        {
            res++;
            int total = busLines.size();
            for(int j=0;j<total;j++)
            {
                int elem = busLines.front();
                busLines.pop();
                for(int i=0;i<routes[elem].size();i++)
                {
                    if(routes[elem][i]==target) return res;
                    addBusSetFromCorrispondingBusStop(routes, routes[elem][i]);
                }
            }
        }
        return -1;
    }
    
private:
    void setupGraph(vector<vector<int>>& routes)
    {
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                intersections[routes[i][j]].push_back(i);
            }
        }
    }
    
    void addBusSetFromCorrispondingBusStop(vector<vector<int>>& routes, int node)
    {
        for(int k=0;k<intersections[node].size();k++)
        {
            int newSet = intersections[node][k];
            if(visitedSet.find(newSet)==visitedSet.end())
            {
                busLines.push(newSet);
                visitedSet.insert(newSet);
            }
        }
    }
    
    map<int,vector<int>> intersections;
    queue<int> busLines;
    int res;
    set<int> visitedSet;
};