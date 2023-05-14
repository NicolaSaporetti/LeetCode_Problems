#include <vector>
#include <priority_queue>
#include <set>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> chairs;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq_arri;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq_dep;
        vector<int> pos(times.size(),-1);
        int max_el =0;
        for(int i=0;i<times.size();i++) chairs.insert(i);
        for(int i=0;i<times.size();i++)
        {
            pq_arri.push({times[i][0],i});
            pq_dep.push({times[i][1],i});
            max_el = max(max_el,times[i][1]);
        }
        for(int i=0;i<max_el;i++)
        {
            while(pq_dep.top().first==i)
            {
                int person = pq_dep.top().second;
                pq_dep.pop();
                chairs.insert(pos[person]);
                pos[person]=-1;
            }
            if(pq_arri.top().first==i)
            {
                int person = pq_arri.top().second;
                pq_arri.pop();
                pos[person]=*chairs.begin();
                chairs.erase(pos[person]);
                if(person==targetFriend) return pos[person];
            }
        }
        return -1;
    }
};