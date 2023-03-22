#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        multiset<int> s;
        for(auto& e : nums) s.insert(e);
        int tot = 0;
        for(auto& e : nums)
        {
            auto it = s.upper_bound(e);
            if(it!=s.end())
            {
                tot++;
                s.erase(it);
            }
        }
        return tot;
    }
};