#include <priority_queue>
#include <vector>
#include <map>
using namespace std;

auto comp = [](pair<int,int> e1, pair<int,int> e2){return e1.first<e2.first || (e1.first==e2.first && e1.second<e2.second);};

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pqL(comp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pqR(comp);
        map<int,vector<int>> ml;
        map<int,vector<int>> mr;
        for(int i=0;i<k;i++) pqL.push({time[i][0]+time[i][2],i});
        t = 0;
        while(n>0 || !pqR.empty() || !mr.empty())
        {
            if(!pqR.empty())
            {
                int el = pqR.top().second;
                pqR.pop();
                t+=time[el][2];
                ml[t+time[el][3]].push_back(el);
            }
            else if(!pqL.empty() && n>0)
            {
                n--;
                int el = pqL.top().second;
                pqL.pop();
                t+=time[el][0];
                mr[t+time[el][1]].push_back(el);
            }
            else
            {
                int tl = (!ml.empty())? ml.begin()->first : INT_MAX;
                int tr = (!mr.empty())? mr.begin()->first : INT_MAX;
                t = min(tl,tr);
            }
            updatePQ(ml,pqL,time);
            updatePQ(mr,pqR,time);
        }
        return t;
    }
    
private:
    void updatePQ(map<int,vector<int>>& m, priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)>& pq, vector<vector<int>>& time)
    {
        auto it = m.begin();
        while(it!=m.end() && t>=it->first)
        {
            for(int i=0;i<it->second.size();i++)
            {
                int el = it->second[i];
                pq.push({time[el][0]+time[el][2],el});
            }
            m.erase(it++);
        }
    }

    int t;
};