#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        map<int,int> m;
        int res = 0;
        for(auto& e : nums) m[e]++;
        for(auto it = m.begin();it!=m.end();it++) if(it!=m.begin()) it->second+=prev(it)->second;
        if(m.begin()->first!=0) res++;
        for(auto it = m.begin();it!=prev(m.end());it++) if(it->first<it->second && next(it)->first>it->second) res++;
        if(m.rbegin()->first!=nums.size()) res++;
        return res;
    }
};