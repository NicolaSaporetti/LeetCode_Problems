#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        map<int,set<int>> x;
        map<int,set<int>> y;
        queue<pair<int,int>> q;
        for(auto stone : stones)
        {
            x[stone[0]].insert(stone[1]);
            y[stone[1]].insert(stone[0]);
        }
        for(auto it = x.begin();it!=x.end();it++)
        {
            q.push({it->first,*it->second.begin()});
            while(!q.empty())
            {
                pair<int,int> elem = q.front();
                q.pop();
                for(auto ordinate : x[elem.first])
                {
                    if(ordinate == *it->second.begin()) continue;
                    q.push({elem.first,ordinate});
                    
                    x[elem.first].erase(ordinate);
                    y[ordinate].erase(elem.first);
                }
                for(auto asciss : y[elem.second])
                {
                    if(asciss == it->first) continue;
                    q.push({asciss,elem.second});
                    
                    x[asciss].erase(elem.second);
                    y[elem.second].erase(asciss);
                }
            }
            for(auto itx=x.begin();itx!=x.end();)
            {
                if(itx->second.empty()) itx = x.erase(itx);
                else itx++;
            }
            for(auto ity=y.begin();ity!=y.end();)
            {
                if(ity->second.empty()) ity = y.erase(ity);
                else ity++;
            }
        }
        return stones.size()-x.size();
    }
};