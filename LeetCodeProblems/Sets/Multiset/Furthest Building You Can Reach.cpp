#include <multiset>
#include <vector>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> m;
        int sz = heights.size();
        for(int i=0;i<sz-1;i++)
        {
            int d =  heights[i+1]-heights[i];
            if(d>0)
            {
                if(ladders>0)
                {
                    ladders--;
                    m.insert(d);
                }
                else
                {
                    auto it = m.begin();
                    if(!m.empty() && *it<d)
                    {
                        if(*it>bricks) return i;
                        bricks-=*it;
                        m.insert(d);
                        m.erase(it);
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