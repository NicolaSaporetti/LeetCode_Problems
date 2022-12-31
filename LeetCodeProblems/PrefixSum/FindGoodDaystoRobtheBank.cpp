#include <vector>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int sz= security.size();
        vector<int> res;
        vector<int> dec(sz,0);
        vector<int> inc(sz,0);
        for(int i=1;i<sz;i++) if(security[i]<=security[i-1]) dec[i]=dec[i-1]+1;
        for(int i=sz-2;i>=0;i--) if(security[i]<=security[i+1]) inc[i]=inc[i+1]+1;
        for(int i=0;i<sz;i++) if(dec[i]>=time && inc[i]>=time) res.push_back(i);
        return res;
    }
};