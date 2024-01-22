#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> result;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<s.size();i++)
        {
            int val = 0;
            for(int j=0;j<31 && i+j<s.size();j++)
            {
                val*=2;
                val+=s[i+j]-'0';
                if(!m.count(val)) m[val]={i,i+j};
                if(val==0) break;
            }
        }
        for(auto& e : queries)
        {
            int val = e[0]^e[1];
            if(!m.count(val)) result.push_back({-1,-1});
            else result.push_back(m[val]);
        }
        return result;
    }
};