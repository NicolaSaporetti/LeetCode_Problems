#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        set<int> s;
        for(auto i : special)
        {
            s.insert(i);
        }
        int res = 0;
        for(auto it = s.begin();it!=s.end();it++)
        {
            res = max(res, *it-bottom);
            bottom = *it+1;
        }
        res= max(res,top-bottom+1);
        return res;
    }
};