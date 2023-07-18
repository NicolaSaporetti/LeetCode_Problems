#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,unordered_set<int>> m;
        vector<int> res(k,0);
        int high = 0;
        for(auto& l : logs) m[l[0]].insert(l[1]);
        for(auto& [k,v] : m) res[v.size()-1]++;
        return res;
    }
};