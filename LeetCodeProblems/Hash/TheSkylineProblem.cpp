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
        for(auto it=m.begin();it!=m.end();it++)
        {
            for(auto itE=it->second.begin();itE!=it->second.end();itE++)
            {
                if(*itE>0) current[*itE]++;
                else
                {
                    if(current[*itE*-1]==1) current.erase(*itE*-1);
                    else current[*itE*-1]--;
                }
            }
            int newHeight = (!current.empty())? current.rbegin()->first : 0;
            if(newHeight!=oldHeight)
            {
                vector<int> t = {it->first,newHeight};
                res.push_back(t);
                oldHeight = newHeight;
            }
        }
        return res;
    }
};