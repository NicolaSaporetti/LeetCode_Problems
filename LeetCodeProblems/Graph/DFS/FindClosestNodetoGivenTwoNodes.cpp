#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> m1 = buildNodeDistance(edges,node1);
        unordered_map<int,int> m2 = buildNodeDistance(edges,node2);
        int res = INT_MAX;
        int el  = -1;
        for(auto& e : m1)
        {
            auto it = m2.find(e.first);
            if(it!=m2.end())
            {
                int dist = max(e.second,it->second);
                if(res>dist || (res==dist && el> e.first))
                {
                    res = dist;
                    el = e.first;
                }
            }
        }
        return el;
    }
private:
    unordered_map<int,int> buildNodeDistance(vector<int>& edges, int startNode)
    {
        unordered_map<int,int> m;
        int dist = 0;
        m[startNode]=dist++;
        while(edges[startNode]!=-1 && m.find(edges[startNode])==m.end())
        {
            startNode = edges[startNode];
            m[startNode]=dist++;
        }
        return m;
    }
};