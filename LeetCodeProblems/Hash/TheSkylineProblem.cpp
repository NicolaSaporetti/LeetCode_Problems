#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int,set<int>> m;
        map<int,int> current;
        vector<vector<int>> res;
        int oldHeight = -1;
        for(auto i : buildings)
        {
            m[i[0]].insert(i[2]);
            m[i[1]].insert(-i[2]);
        }
        for(auto e : m)
        {
            for(auto h : e.second)
            {
                if(h>0) current[h]++;
                else
                {
                    current[h*-1]--;
                    if(current[h*-1]==0) current.erase(h*-1);
                }
            }
            int newHeight = (!current.empty())? current.rbegin()->first : 0;
            if(newHeight!=oldHeight)
            {
                res.push_back({e.first,newHeight});
                oldHeight = newHeight;
            }
        }
        return res;
    }
};