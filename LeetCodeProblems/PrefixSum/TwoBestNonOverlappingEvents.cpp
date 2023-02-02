#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int,int> suc;
        map<int,int> prec;
        for(auto& e : events)
        {
            suc[e[1]]=max(suc[e[1]],e[2]);
            prec[e[0]]=max(prec[e[0]],e[2]);
        }
        int maxE = 0;
        for(auto& el : suc)
        {
            maxE = max(el.second,maxE);
            el.second = maxE;
        }
        maxE = 0;
        for(auto it = prec.rbegin();it!=prec.rend();it++)
        {
            maxE = max(it->second,maxE);
            it->second = maxE;
        }
        int result = 0;
        for(auto& el : suc)
        {
            auto it = prec.upper_bound(el.first);
            if(it!=prec.end()) result = max(result,el.second+it->second);
            else result = max(result,el.second);
        }
        return result;
    }
};