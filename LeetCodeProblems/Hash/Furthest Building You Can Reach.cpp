#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        map<int,int> m;
        int sz = heights.size();
        for(int i=0;i<sz-1;i++)
        {
            int d =  heights[i+1]-heights[i];
            if(d>0)
            {
                if(ladders>0)
                {
                    ladders--;
                    m[d]++;
                }
                else
                {
                    if(!m.empty() && m.begin()->first<d)
                    {
                        int d1 = m.begin()->first;
                        m[d1]--;
                        if(m[d1]==0) m.erase(d1);
                        if(d1>bricks) return i;
                        m[d]++;
                        bricks-=d1;
                    }
                    else
                    {
                        if(d>bricks) return i;
                        bricks-=d;
                    }
                }
            }
        }
        return sz-1;
    }
};