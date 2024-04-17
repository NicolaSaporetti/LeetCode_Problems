#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> s;
        for(auto e : points) s.insert(e[0]);
        int r = 0;
        auto it = s.begin();
        while(it!=s.end())
        {
            r++;
            it = s.upper_bound(*it+w);
        }
        return r;
    }
};