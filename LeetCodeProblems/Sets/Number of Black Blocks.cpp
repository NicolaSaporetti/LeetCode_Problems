#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coord) {
        unordered_set<long long> s;
        long long base = 1000000;
        for(auto e : coord)
        {
            long long v = (long long)e[0]*base+e[1];
            s.insert(v);
        }
        vector<long long> r(5,0);
        r[0]=(long long)(m-1)*(long long)(n-1);
        for(auto e : s)
        {
            long long y = e%base;
            long long x = e/base;
            int x00 = (s.count((x-1)*base+y-1)>0);
            int x01 = (s.count((x-1)*base+y)>0);
            int x02 = (s.count((x-1)*base+y+1)>0);
            int x10 = (s.count(x*base+y-1)>0);
            int x12 = (s.count(x*base+y+1)>0);
            int x20 = (s.count((x+1)*base+y-1)>0);
            int x21 = (s.count((x+1)*base+y)>0);
            int x22 = (s.count((x+1)*base+y+1)>0);
            if(x>0 && y>0 && !x00 && !x01 && !x10) r[1]++;
            if(x>0 && y<n-1 && !x01 && !x02) r[1+x12]++;
            if(x<m-1 && y>0 && !x10) r[1+x20+x21]++;
            if(x<m-1 && y<n-1) r[1+x12+x21+x22]++;
        }
        for(int i=1;i<5;i++) r[0]-=r[i];
        return r;
    }
};