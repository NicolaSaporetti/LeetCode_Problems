#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int,vector<int>> m;
        int res = 0;
        int val = 0;
        for(int i=0;i<properties.size();i++)
        {
            m[properties[i][0]].push_back(properties[i][1]);
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            sort(it->second.begin(),it->second.end());
        }
        
        for(auto it = m.rbegin();it!=m.rend();it++)
        {
            int pos = static_cast<int>(lower_bound(it->second.begin(),it->second.end(),val)-it->second.begin());
            res+=pos;
            val = max(val,it->second[it->second.size()-1]);
        }
        return res;
    }
};