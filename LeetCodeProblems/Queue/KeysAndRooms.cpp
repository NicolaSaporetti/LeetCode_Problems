#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int sz = rooms.size();
        vector<bool> vis(sz,false);
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            int room = q.front();
            q.pop();
            for(auto& key : rooms[room])
            {
                if(!vis[key])
                {
                    q.push(key);
                    vis[key]=true;
                }
            }
        }
        return all_of(begin(vis),end(vis),[](int isVisited){return isVisited;});
    }
};