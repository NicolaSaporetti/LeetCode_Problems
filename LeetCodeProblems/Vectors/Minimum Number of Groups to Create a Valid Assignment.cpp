#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        map<int,int> t;
        for(auto e : nums) t[e]++;
        for(auto& [k,v] : t) m[v]++;
        mine = m.begin()->first;
        for(int i=1;i<=mine;i++)
        {
            int gr = mine/i;
            int divU = divide(gr, gr+1);
            if(divU!=-1) return divU;
            if(gr>0) divU = divide(gr-1, gr);
            if(divU!=-1) return divU;
        }
        return -1;
    }
private:
    int divide(int g1, int g2)
    {
        int g =0;
        for(auto& [k,v]: m)
        {
            int gn = k/g1;
            int r = k%g1;
            if(r>gn) return -1;
            gn=k/(g2);
            if(k%g2!=0) gn++;
            g+=(gn*v);
        }
        return g;
    }
    
    map<int,int> m;
    int mine;
};