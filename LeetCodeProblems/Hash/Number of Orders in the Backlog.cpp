#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int mod = 1e9+7;
        map<int,long long> buy;
        map<int,long long> sell;
        for(int i=0;i<orders.size();i++)
        {
            long long num = orders[i][1];
            int val = orders[i][0];
            if(orders[i][2]==0)
            {
                auto it = sell.begin();
                while(it!=sell.end() && it->first<=val && num>0)
                {
                    long long sub = min(num,it->second);
                    it->second-=sub;
                    num-=sub;
                    if(it->second==0) sell.erase(it++);
                }
                if(num>0) buy[val]+=num;
            }
            else
            {
                auto it = buy.rbegin();
                while(it!=buy.rend() && it->first>=val && num>0)
                {
                    long long sub = min(num,it->second);
                    it->second-=sub;
                    num-=sub;
                    if(it->second==0) buy.erase(next(it++).base());
                }
                if(num>0) sell[val]+=num;
            }
        }
        long long res = 0;
        for(auto& [k,v] : buy) res+=v;
        for(auto& [k,v] : sell) res+=v;
        return res%mod;
    }
};