#include <map>
using namespace std;

class CountIntervals {
public:
    void add(int left, int right) {
        auto it = m.upper_bound(left);
        if (it != begin(m) && prev(it)->second >= left)
        {
            it = prev(it);
            left = it->first;
        }
        for (; it != end(m) && it->first <= right; m.erase(it++)) {
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
        }
        cnt += right - left + 1;
        m[left] = right;
    }
    
    int count() { return cnt; }
    
private:
    map<int, int> m;
    int cnt = 0;
};