#include <unordered_multiset>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int r = 0;
        multiset<long long> s;
        for(auto e : nums) s.insert(e);
        auto it = s.begin();
        while(true)
        {
            auto it = s.begin();
            if(*it<k)
            {
                long long v1 = *it;
                s.erase(it);
                it = s.begin();
                long long v2 = *it;
                s.erase(it);
                s.insert(min(v1,v2)*2+max(v1,v2));
                r++;
            }
            else break;
        }
        return r;
    }
};