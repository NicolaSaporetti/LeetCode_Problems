#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int,vector<int>> m;
        vector<vector<int>> result;
        for(int i=0;i<points.size();i++) m[points[i][0]*points[i][0]+points[i][1]*points[i][1]].push_back(i);
        for(auto it=m.begin();it!=m.end() && k>0; it++)
        {
            for(int i=0;i<it->second.size() && k>0;i++)
            {
                result.push_back({points[it->second[i]][0],points[it->second[i]][1]});
                k--;
            }
        }
        return result;
    }
};