#include <priority_queue>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        convertMeetings(meetings);
        vector<int> res(n,0);
        for(int i=0; i<n; ++i) s.insert(s.end(),i);
        for(int i=0;i<meetings.size();i++)
        {
            long long start = meetings[i][0];
            long long duration = meetings[i][1]-start;
            while(!pq.empty() && pq.top().first<=start)
            {
                s.insert(pq.top().second);
                pq.pop();
            }
            if(s.empty())
            {
                s.insert(pq.top().second);
                start = pq.top().first;
                pq.pop();
            }
            int room = *s.begin();
            s.erase(room);
            res[room]++;
            pq.push(make_pair(start+duration,room));
        }
        return max_element(res.begin(),res.end())-res.begin();
    }
    
private:
    void convertMeetings(vector<vector<int>>& meetings)
    {
        map<int,int> m;
        for(int i=0;i<meetings.size();i++)
        {
            m[meetings[i][0]]=meetings[i][1];
        }
        int j=0;
        for(auto it = m.begin();it!=m.end();it++,j++)
        {
            meetings[j][0]=it->first;
            meetings[j][1]=it->second;
        }
    }
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    set<int> s;
};