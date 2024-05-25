#include <unordered_map>
using namespace std;

class Solution {
public:
    int waysToReachStair(int k) {
        unordered_map<int,int> m;
        m[1]=1;
        int r = 0;
        int j = 0;
        while(!m.empty())
        {
            map<int,int> m1;
            for(auto [key,v] : m)
            {
                if(key<=k+1)
                {
                    if(key==k) r+=v;
                    if(key==k+1) r+=v;
                    int npos = key+(1<<j);
                    m1[npos]+=v;
                    if(key>0) m1[npos-1]+=v;
                }
            }
            m = m1;
            j++;
        }
        return r;
    }
};