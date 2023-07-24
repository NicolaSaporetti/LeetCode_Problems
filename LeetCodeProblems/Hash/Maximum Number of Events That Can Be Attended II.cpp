#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));
        int sz = events.size();
        int res = 0;
        vector<map<int,int>> dp(k+1);
        dp[0][0]=0;
        for(int j=0;j<k;j++)
        {
            dp[j+1][0]=0;
            for(int i=0;i<sz;i++)
            {
                auto it = dp[j].lower_bound(events[i][0]);
                auto it2 = dp[j+1].upper_bound(events[i][1]);
                int nv = max(events[i][2]+prev(it)->second,prev(it2)->second);
                if(events[i][2]+prev(it)->second>prev(it2)->second)
                {
                    dp[j+1][events[i][1]]=max(dp[j+1][events[i][1]],nv);
                    auto it3 = dp[j+1].find(events[i][1]);
                    while(next(it3)!=dp[j+1].end() && it3->second>=next(it3)->second) dp[j+1].erase(next(it3));
                }
            }
        }
        for(auto& [key,v] : dp[k]) res = max(res,v);
        return res;
    }
};