#include <set>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) 
    {
        int tot=0;
        multiset<int> s;
        for(auto& e : nums) s.insert(e);
        for(int i=0;i<k;i++)
        {
            auto it = s.rbegin();
            s.insert(*it/2+*it%2);
            s.erase(std::next(it).base());
        }
        for(auto e : s) tot+=e;
        return tot;
    }
};