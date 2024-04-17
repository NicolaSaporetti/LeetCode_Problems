#include <vector>
using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> r;
        map<int,int> m;
        for(int i=0;i<grid.size();i++)
        {
            int sum = 0;
            for(int j=0;j<grid[0].size();j++)
            {
                sum*=2;
                sum+=grid[i][j];
            }
            m[sum]=i;
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            if(it->first==0)
            {
                r.push_back(it->second);
                break;
            }
            for(auto [k,v] : m)
            {
                if(!(k&it->first))
                {
                    r.push_back(it->second);
                    r.push_back(v);
                    sort(begin(r),end(r));
                    return r;
                }
            }
        }
        return r;
    }
};