#include <vector>
#include <map>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjoinSetUnion d(n);
        vector<bool> r(queries.size());
        map<int,vector<int>> e;
        map<int,vector<int>> q;
        for(int i=0;i<queries.size();i++) q[queries[i][2]].push_back(i);
        for(int i=0;i<edgeList.size();i++) e[edgeList[i][2]].push_back(i);
        auto it = e.begin();
        for(auto& [k,v] : q)
        {
            while(it!=e.end() && it->first<k)
            {
                for(auto& el : it->second)
                {
                    d.connect(edgeList[el][0],edgeList[el][1]);
                }
                it++;
            }
            for(auto& el : v)
            {
                r[el] = d.are_connect(queries[el][0],queries[el][1]);
            }
        }
        return r;
    }
};