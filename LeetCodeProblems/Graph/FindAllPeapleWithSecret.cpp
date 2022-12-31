#include <map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>> m;
        vector<int> res;
        vector<bool> r(n,false);
        r[0]=true;
        r[firstPerson]=true;
        for(auto& e : meetings) m[e[2]].push_back({e[0],e[1]});
        for(auto& t : m)
        {
            map<int,vector<int>> graph;
            for(int i=0;i<t.second.size();i++)
            {
                graph[t.second[i].first].push_back(t.second[i].second);
                graph[t.second[i].second].push_back(t.second[i].first);
            }
            queue<int> q;
            for(auto& e : graph) if(r[e.first]) q.push(e.first);
            while(!q.empty())
            {
                int el = q.front();
                q.pop();
                for(int i=0;i<graph[el].size();i++)
                {
                    int newEl = graph[el][i];
                    if(!r[newEl])
                    {
                        r[newEl]=true;
                        q.push(newEl);
                    }
                }
            }
        }
        for(int i=0;i<n;i++) if(r[i]) res.push_back(i);
        return res;
    }
};