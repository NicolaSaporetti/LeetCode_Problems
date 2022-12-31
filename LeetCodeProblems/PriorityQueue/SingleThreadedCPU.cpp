#include <priority_queue>
#include <vector>
using namespace std;

struct myComp {
    bool operator() (pair<int, int> const& top_pq,
                     pair<int, int> const& new_el)
    {
        return top_pq.first > new_el.first || (top_pq.first==new_el.first && top_pq.second > new_el.second);
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> pq;
        map<int,vector<pair<int,int>>> m;
        for(int i=0;i<tasks.size();i++) m[tasks[i][0]].push_back({tasks[i][1],i});
        auto it = m.begin();
        long long threshold = -1;
        long long time = 0;
        for(auto it = m.begin();it!=m.end();)
        {
            time = it->first;
            for(int i=0;i<it->second.size();i++) pq.push({it->second[i].first,it->second[i].second});
            it++;
            threshold = (it!=m.end())? it->first : time+1;
            while(!pq.empty())
            {
                auto el = pq.top();
                pq.pop();
                result.push_back(el.second);
                time+=el.first;
                while(time>=threshold && it!=m.end())
                {
                    for(int i=0;i<it->second.size();i++) pq.push({it->second[i].first,it->second[i].second});
                    it++;
                    threshold = (it!=m.end())? it->first : time+1;
                }
            }
        }
        return result;
    }
};