#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> s;
        for(auto e : nums) s.insert(e);
        for(int i=0;i<moveFrom.size();i++)
        {
            if(moveFrom[i]!=moveTo[i])
            {
                s.insert(moveTo[i]);
                s.erase(moveFrom[i]);
            }
        }
        vector<int> r;
        for(auto e : s) r.push_back(e);
        sort(begin(r),end(r));
        return r;
    }
};