#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int,vector<int>> intersection;
        vector<bool> vis(routes.size(),false);
        for(int j=0;j<routes.size();j++)
            for(auto& node : routes[j]) intersection[node].push_back(j);
        queue<int> q;
        for(auto& busLine : intersection[source])
        {
            q.push(busLine);
            vis[busLine]=true;
        }
        int dist =0;
        while(!q.empty())
        {
            dist++;
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                int route = q.front();
                q.pop();
                for(auto& point : routes[route])
                {
                    if(point==target) return dist;
                    for(auto& route : intersection[point])
                        if(!vis[route])
                        {
                            q.push(route);
                            vis[route]=true;
                        }
                }
            }
        }
        return -1;
    }
};