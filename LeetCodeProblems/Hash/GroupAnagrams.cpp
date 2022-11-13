#include <vector>
#include <array>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int,26>,vector<int>> m;
        vector<vector<string>> results;
        for(int i=0;i<strs.size();i++)
        {
            array<int,26> base = {};
            for(int j=0;j<strs[i].size();j++) base[strs[i][j]-'a']++;
            m[base].push_back(i);
        }
        results.resize(m.size());
        int i=0;
        for(auto& mp : m)
        {
            for(auto e : mp.second) results[i].push_back(strs[e]);
            i++;
        }
        return results;
    }
};