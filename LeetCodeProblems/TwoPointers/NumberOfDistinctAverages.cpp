#include <multiset>
#include <set>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        multiset<int> ms;
        set<double> s;
        for(auto i : nums) ms.insert(i);
        auto it = ms.begin();
        auto it2 = prev(ms.end());
        while(ms.size()>0)
        {
            s.insert((double(*it)+double(*it2))/2);
            ms.erase(it++);
            ms.erase(it2--);
        }
        return s.size();
    }
};