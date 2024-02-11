#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long,int> m;
        int res = 0;
        for(auto e : nums) m[e]++;
        if(m.count(1)>0)
        {
            res = max(res,m[1]);
            m.erase(1);
        }
        while(m.size()>0)
        {
            int tot = 0;
            auto it = m.begin();
            long long k = it->first;
            int v = it->second;
            while(true)
            {
                m.erase(k);
                if(v==1) tot++;
                else tot+=2;
                res = max(res,tot);
                if(v==1) break;
                if(m.count(k*k)>0)
                {
                    k=k*k;
                    v=m[k];
                }
                else break;
            }
        }
        return (res%2==0)? res-1 : res;
    }
};