#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        map<int, int> m;
        for(auto i : intervals)
        {
            int left = i[0];
            int right = i[1];
            auto it = m.lower_bound(left);
            if (it != begin(m) && prev(it)->second >= left)
            {
                it = prev(it);
                left = it->first;
            }
            for (; it != m.end() && it->first <= right; m.erase(it++)) {
                right = max(right, it->second);
            }
            m[left] = right;
        }
        for(auto it = m.begin();it!=m.end();it++) result.push_back({it->first, it->second});
        return result;
    }
};