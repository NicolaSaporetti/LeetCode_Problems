#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<unordered_set<int>> v;
        for(auto& e : nums)
        {
            bool found = false;
            for(int i=0;i<v.size() && !found;i++)
            {
                if(v[i].find(e)==v[i].end())
                {
                    v[i].insert(e);
                    found = true;
                }
            }
            if(!found)
            {
                v.push_back({e});
            }
        }
        vector<vector<int>> res(v.size());
        for(int i=0;i<v.size();i++)
        {
            for(auto& el : v[i]) res[i].push_back(el);
        }
        return res;
    }
};