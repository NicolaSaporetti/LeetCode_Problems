#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> m;
        for(auto e : nums) m[e]++;
        map<int,vector<int>> m2;
        for(auto [k,v] : m) m2[v].push_back(k);
        vector<vector<int>> r(m2.rbegin()->first);
        for(auto [k,v] : m2)
        {
            for(int i=0;i<k;i++)
                for(auto e : v) r[i].push_back(e); 
        }
        return r;
    }
};