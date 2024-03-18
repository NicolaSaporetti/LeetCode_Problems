#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        map<int,vector<int>> start;
        map<int,vector<int>> end;
        for(int i=0;i<points.size();i++)
        {
            start[points[i][0]].push_back(i);
            end[points[i][1]].push_back(i);
        }
        unordered_set<int> pop;
        auto it = start.begin();
        int r = 0;
        for(auto [k,v]: end)
        {
            for(auto e : v)
            {
                if(pop.count(e)>0) continue;
                r++;
                for(;it!=start.end() && it->first<=k;it++)
                    for(int i=0;i<it->second.size();i++)
                        pop.insert(it->second[i]);
            }
        }
        return r;
    }
};