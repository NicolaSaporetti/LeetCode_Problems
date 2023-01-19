#include <set>
#include <vector>
#include "DisjoinSet.cpp"
using namespace std;

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> result;
        DisjoinSet ds(n);
        vector<vector<int>> res(n);
        for(auto& r : restrictions)
        {
            res[r[0]].push_back(r[1]);
            res[r[1]].push_back(r[0]);
        }
        for(auto& req : requests)
        {
            set<int> s1 = ds.get_element_with_root_x(req[0]);
            set<int> s2 = ds.get_element_with_root_x(req[1]);
            bool canBeFriend = isCompatible(s1,s2,res);
            result.push_back(canBeFriend);
            if(canBeFriend) ds.connect(req[0],req[1]);
        }
        return result;
    }
private:
    bool isCompatible(set<int>& s1, set<int> s2, vector<vector<int>>& res)
    {
        for(auto& e : s1)
        {
            for(auto& r : res[e])
            {
                if(s2.find(r)!=s2.end()) return false;
            }
        }
        return true;
    }
};