#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        map<long long,long long> m;
        m[0]=0;
        for(auto e : inventory) m[e]++;
        auto it = m.rbegin();
        long long res = 0;
        int mod = 1e9+7;
        while(orders>0)
        {
            long long d = it->first-next(it)->first;
            long long score = (it->first*(it->first+1))/2;
            if(d*it->second>orders)
            {
                d = orders/it->second;
                orders-=d*it->second;
                long long target = it->first-d;
                score-=(target*(target+1))/2;
                score%=mod;
                score*=it->second;
                score%=mod;
                res=(res+score)%mod;
                res=(res+orders*target)%mod;
                orders = 0;
            }
            else
            {
                long long steps = it->first-next(it)->first;
                score-=(next(it)->first*(next(it)->first+1))/2;
                score%=mod;
                score*=it->second;
                score%=mod;
                res=(res+score)%mod;
                orders-=steps*it->second;
                next(it)->second+=it->second;
                it++;
            }
        }
        return res;
    }
};