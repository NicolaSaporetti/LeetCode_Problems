#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        set<int> s;
        for(int i=1;i<nums.size();i++) if(nums[i-1]%2==nums[i]%2) s.insert(i);
        vector<bool> r;
        for(auto e : queries)
        {
            auto it = s.upper_bound(e[0]);
            if(it!=s.end() && *it<=e[1]) r.push_back(false);
            else r.push_back(true);
        }
        return r;
    }
};