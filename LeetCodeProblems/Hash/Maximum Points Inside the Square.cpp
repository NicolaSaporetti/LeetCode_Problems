#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int sz = points.size();
        map<int,vector<char>> m;
        unordered_set<char> ss;
        for(int i=0;i<sz;i++) m[max(abs(points[i][0]),abs(points[i][1]))].push_back(s[i]);
        int r = 0;
        for(auto [k,v] : m)
        {
            for(auto e : v)
            {
                if(ss.count(e)>0) return r;
                else ss.insert(e);
            }
            r = ss.size();
        }
        return r;
    }
};