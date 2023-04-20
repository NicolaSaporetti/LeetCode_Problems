#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int sz = properties.size();
        int res = 0;
        vector<pair<int,int>> v;
        for(auto& e : properties) v.push_back({e[0],e[1]});
        sort(begin(v),end(v));
        int el = v.back().first;
        int maxY = v.back().second;
        int newM = 0;
        int curVal = 0;
        for(int i=sz-2;i>=0;i--)
        {
            if(v[i].first<v[i+1].first) maxY = max(maxY, newM);
            if(v[i].first<el && v[i].second<maxY) res++;
            if(v[i].second>=maxY) newM = max(newM,v[i].second);
        }
        return res;
    }
};