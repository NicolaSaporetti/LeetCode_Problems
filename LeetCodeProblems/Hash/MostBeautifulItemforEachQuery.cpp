#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int> m;
        for(auto& e : items) m[e[0]]=max(m[e[0]],e[1]);
        int val = m.begin()->second;
        for(auto& e : m)
        {
            val = max(e.second, val);
            e.second = val;
        }
        vector<int> res;
        for(auto& q : queries)
        {
            auto it = m.lower_bound(q);
            if(it==m.begin() && it->first!=q) res.push_back(0);
            else
            {
                if(it==m.end() || it->first!=q) it= prev(it);
                res.push_back(it->second);
            }
        }
        return res;
    }
};