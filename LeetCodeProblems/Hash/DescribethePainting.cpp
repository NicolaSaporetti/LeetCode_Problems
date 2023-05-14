#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> m;
        vector<vector<long long>> result;
        for(int i=0;i<segments.size();i++)
        {
            m[segments[i][0]]+=(long long)segments[i][2];
            m[segments[i][1]]-=(long long)segments[i][2];
        }
        auto it = m.begin();
        int start = it->first;
        long long val = it->second;
        for(it++;it!=m.end();it++)
        {
            if(val>0) result.push_back({start,it->first,val});
            val+=it->second;
            start = it->first;
        }
        return result;
    }
};