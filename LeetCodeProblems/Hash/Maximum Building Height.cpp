#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        map<int,int> h;
        map<int,vector<int>> m;
        int res = 0;
        for(auto& r : restrictions) m[r[1]].push_back(r[0]);
        h[1]=0;
        for(auto& [k,v] : m)
        {
            for(auto& e : v)
            {
                auto itb = prev(h.lower_bound(e));
                int els = itb->first;
                int hs = itb->second;
                auto ita = h.upper_bound(e);
                if(ita==h.end())
                {
                    h[e]=min(k,hs+e-els);
                    res = max(res, h[e]);
                }
                else
                {
                    int elf = ita->first;
                    int hf = ita->second;
                    h[e]=min(k,min(hs+e-els,hf+elf-e));
                    res = max(res, h[e]);
                }
            }
        }
        for(auto it=h.begin();it!=h.end();it++)
        {
            if(next(it)==h.end())
            {
                res = max(res,it->second+n-it->first);
            }
            else
            {
                auto its = next(it);
                int d = its->first-it->first;
                int dif = abs(it->second-its->second);
                d-=dif;
                res = max(res,max(it->second,its->second)+d/2);
            }
        }
        return res;
    }
};