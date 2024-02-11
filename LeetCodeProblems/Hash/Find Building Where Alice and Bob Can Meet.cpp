#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        map<int,int> m;
        int sz = queries.size();
        vector<int> res(sz,-1);
        vector<vector<int>> q;
        for(int i=0;i<sz;i++) q.push_back({min(queries[i][0],queries[i][1]),max(queries[i][0],queries[i][1]),i});
        sort(begin(q),end(q),[](vector<int>& v1, vector<int>&v2){
            return v2[1]<v1[1];});
        int i=heights.size()-1;
        for(auto& e : q)
        {
            while(i>=0 && i>e[1])
            {
                m[heights[i]]=i;
                auto it = m.find(heights[i]);
                while(it!=m.begin()) m.erase(prev(it));
                i--;
            }
            if(heights[e[1]]>heights[e[0]] || e[1]==e[0]) res[e[2]]=e[1];
            else
            {
                auto it = m.upper_bound(heights[e[0]]);
                if(it!=m.end()) res[e[2]]=(it->second);
            }
        }
        return res;
    }
};