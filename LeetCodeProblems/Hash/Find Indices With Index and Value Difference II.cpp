#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        map<int,set<int>> m;
        int sz = nums.size();
        for(int i=indexDifference;i<sz;i++)
        {
            m[nums[i]].insert(i);
        }
        for(int i=0;i<sz-indexDifference;i++)
        {
            auto it = m.lower_bound(nums[i]+valueDifference);
            if(it!=m.end())
            {
                return {i,*it->second.begin()};
            }
            it = m.upper_bound(nums[i]-valueDifference);
            if(it!=m.begin())
            {
                return {i,*prev(it)->second.begin()};
            }
            if(i+indexDifference<sz)
            {
                int id = i+indexDifference;
                m[nums[id]].erase(id);
                if(m[nums[id]].empty()) m.erase(nums[id]);
            }
        }
        return {-1,-1};
    }
};