#include <vector>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = INT_MAX;
        int sz = s.size();
        int z = count_if(s.begin(),s.begin(),[](char el){return (el=='0');});
        int o = sz-z;
        vector<int> v(sz,0);
        for(int i=0;i<sz;i++)
        {
            v[i]=(s[i]=='0')? 0 : 1;
            if(i>0) v[i]+=v[i-1];
        }
        res = min(res,sz-v[sz-1]);
        for(int i=0;i<sz;i++) res = min(res,v[i]+(sz-1-i-(v[sz-1]-v[i])));
        return res;
    }
};