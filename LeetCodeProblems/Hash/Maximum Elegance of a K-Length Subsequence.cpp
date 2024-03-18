#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        map<long long,vector<int>> m;
        map<long long,long long> cat;
        map<long long,vector<int>> taken;
        for(auto e : items) m[e[0]].push_back(e[1]);
        auto it = m.rbegin();
        long long prof = 0;
        while(k>0)
        {
            int t = min(k,(int)it->second.size());
            k-=t;
            for(int i=0;i<t;i++)
            {
                taken[it->first].push_back(it->second.back());
                cat[it->second.back()]++;
                it->second.pop_back();
                prof+=it->first;
            }
            if(it->second.empty()) m.erase(next(it++).base());
        }
        long long res = prof+(long long)cat.size()*(long long)cat.size(); 
        auto it2 = m.rbegin();
        int idx = 0;
        for(auto it = taken.begin();it!=taken.end();it++)
        {
            for(int i=0;i<it->second.size();i++)
            {
                if(cat[it->second[i]]>1)
                {
                    while(it2!=m.rend())
                    {
                        bool found = false;
                        for(;idx<it2->second.size() && !found;idx++)
                        {
                            if(cat.count(it2->second[idx])==0)
                            {
                                prof-=it->first;
                                prof+=it2->first;
                                cat[it->second[i]]--;
                                cat[it2->second[idx]]=1;
                                res = max(res,prof+(long long)cat.size()*(long long)cat.size());
                                found = true;
                            }
                        }
                        if(!found)
                        {
                            it2++;
                            idx=0;
                        }
                        else break;
                    }
                }
            }
        }
        return res;
    }
};