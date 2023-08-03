#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs));
        map<int,int> m;
        m[-1001]=0;
        for(auto& e : pairs)
        {
            auto it = prev(m.lower_bound(e[0]));
            if(m.count(e[1])==0)
            {
                m[e[1]]=it->second+1;
                it = m.find(e[1]);
                if(prev(it)->second>=it->second) m.erase(it);
                else while(next(it)!=m.end() && next(it)->second>=it->second) m.erase(next(it));
            }
        }
        return m.rbegin()->second;
    }
};