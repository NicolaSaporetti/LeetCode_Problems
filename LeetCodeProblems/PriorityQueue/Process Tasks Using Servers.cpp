#include <priority_queue>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        for(int i=0;i<servers.size();i++) ava_s[servers[i]].insert(i);
        t = 0;
        for(;t<tasks.size();t++)
        {
            q.push({tasks[t],t});
            scheduleTasks(servers);
        }
        while(!q.empty())
        {
            t = pq.top().first;
            scheduleTasks(servers);
        }
        return res;
    }
    
private:
    void scheduleTasks(vector<int>& servers)
    {
        while(!pq.empty() && pq.top().first==t)
        {
            int serv = pq.top().second;
            pq.pop();
            ava_s[servers[serv]].insert(serv);
        }
        while(!q.empty() && ava_s.size())
        {
            int weight = ava_s.begin()->first;
            int serv =*ava_s.begin()->second.begin();
            ava_s.begin()->second.erase(serv);
            if(ava_s.begin()->second.size()==0) ava_s.erase(weight);
            auto task = q.front();
            q.pop();
            pq.push({t+task.first,serv});
            res.push_back(serv);
        }
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    queue<pair<int,int>> q;
    map<int,set<int>> ava_s;
    vector<int> res;
    int t;
};