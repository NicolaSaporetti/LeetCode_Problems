#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        map<int,vector<int>> m;
        map<int,vector<pair<int,int>>> query;
        int sz = queries.size();
        vector<int> res(sz,0);
        set<int> ava;
        for(int i=0;i<sz;i++) query[queries[i][1]].push_back({queries[i][0],i});
        for(auto& r : rooms) m[r[1]].push_back(r[0]);
        auto itr = m.rbegin();
        for(auto it = query.rbegin();it!=query.rend();it++)
        {
            while(itr!=m.rend() && itr->first>=it->first)
            {
                for(auto& r : itr->second) ava.insert(r);
                itr++;
            }
            for(auto& e : it->second)
            {
                int pref = e.first;
                int val = -1;
                if(ava.size()!=0)
                {
                    auto it2 = ava.lower_bound(pref);
                    if(it2==ava.end()) val = *prev(it2);
                    else
                    {
                        if(it2!=ava.begin())
                        {
                            auto itp = prev(it2);
                            val = (*it2-pref<pref-*itp)? *it2 : *itp;
                        }
                        else val = *it2;
                    }
                }
                res[e.second]=val;
            }
        }
        return res;
    }
};