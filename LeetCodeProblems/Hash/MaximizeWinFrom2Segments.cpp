#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        map<int,int> mR =buildRightSum(prizePositions,k);
        map<int,int> mL=buildLeftSum(prizePositions,k);
        map<int,int> v;
        int res = 0;
        
        for(auto& [key,val] : mL) v[val]++;
        auto it = mL.begin();
        for(auto& [key,val] : mR)
        {
            v[it->second]--;
            if(v[it->second]==0) v.erase(it->second);
            int v2 = (v.empty())? 0 : v.rbegin()->first;
            res = max(res,val+v2);
            it++;
        }
        return res;
    }
    
private:
    map<int,int> buildRightSum(vector<int>& prizePositions, int k)
    {
        map<int,int> m;
        for(auto& p : prizePositions) m[p]++;
        int prevV = 0;
        for(auto& [key,val] : m)
        {
            prevV+=val;
            val = prevV;
        }
        for(auto it=m.rbegin();it!=m.rend();it++)
        {
            auto itL=m.lower_bound(it->first-k);
            it->second -=(itL!=m.begin())? prev(itL)->second :0;
        }
        return m;
    }
    
    map<int,int> buildLeftSum(vector<int>& prizePositions, int k)
    {
        map<int,int> m;
        for(auto& p : prizePositions) m[p]++;
        int prevV = 0;
        for(auto it = m.rbegin();it!=m.rend();it++)
        {
            prevV+=it->second;
            it->second=prevV;
        }
        for(auto& [key,val] : m)
        {
            auto it=m.upper_bound(key+k);
            val-=(it!=m.end())? it->second : 0;
        }
        return m;
    }
};