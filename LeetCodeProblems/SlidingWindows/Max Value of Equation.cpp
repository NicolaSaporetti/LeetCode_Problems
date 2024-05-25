#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        map<int,int> m;
        int s = 0;
        int r = INT_MIN;
        for(int i=0;i<p.size();i++)
        {
            while(s<i && p[i][0]-p[s][0]>k)
            {
                int dif = p[s][1]-p[s][0];
                if(--m[dif]==0) m.erase(dif);
                s++;
            }
            int dif = p[i][1]-p[i][0];
            if(m.size()>0)
            {
                r = max(r,p[i][1]+p[i][0]+m.rbegin()->first);
            }
            m[dif]++;
        }
        return r;
    }
};