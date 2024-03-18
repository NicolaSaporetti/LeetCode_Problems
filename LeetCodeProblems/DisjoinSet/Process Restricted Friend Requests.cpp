#include <vector>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& bans, vector<vector<int>>& requests) {
        vector<bool> ans;
        DisjoinSetUnion ds(n);
        for (auto &r : requests) {
            int r1 = ds.find_set(r[0]);
            int r2 = ds.find_set(r[1]);
            bool valid = true;
            if (!ds.are_connect(r1, r2)) {
                for (auto &b : bans) {
                    int x = ds.find_set(b[0]), y = ds.find_set(b[1]);
                    if ((x == r1 && y == r2) || (x == r2 && y == r1))
                    {
                        valid = false;
                        break;
                    }
                }
            }
            ans.push_back(valid);
            if (valid) ds.connect(r1, r2);
        }
        return ans;
    }
};