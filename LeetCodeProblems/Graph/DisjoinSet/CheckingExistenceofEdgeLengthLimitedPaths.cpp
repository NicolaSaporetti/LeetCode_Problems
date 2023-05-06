#include <vector>
#include <map>
#include "DisjoinSet.cpp"
using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> res(queries.size(),false);
        map<int,vector<int>> edges;
        for(int i=0;i<edgeList.size();i++) edges[edgeList[i][2]].push_back(i);
        map<int,vector<int>> query;
        for(int i=0;i<queries.size();i++) query[queries[i][2]].push_back(i);
        DisjoinSet ds(n);
        auto edges_it = edges.begin();
        for(auto it = query.begin();it!=query.end();it++)
        {
            while(edges_it!=edges.end() && edges_it->first<it->first)
            {
                for(int i=0;i<edges_it->second.size();i++)
                {
                    int el = edges_it->second[i];
                    ds.connect_fast(edgeList[el][0],edgeList[el][1]);
                }
                edges_it++;
            }
            for(int i=0;i<it->second.size();i++)
            {
                int el = it->second[i];
                if(ds.are_connect(queries[el][0],queries[el][1])) res[el]=true;
            }
        }
        return res;
    }
};