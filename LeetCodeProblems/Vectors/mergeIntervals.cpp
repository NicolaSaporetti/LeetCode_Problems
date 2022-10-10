#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
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
            for (; it != end(m) && it->first <= right; m.erase(it++)) {
                right = max(right, it->second);
            }
            m[left] = right;
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            vector<int> a {it->first, it->second};
            result.push_back(a);
        }
        return result;
    }
    
private:
    map<int, int> m;
};