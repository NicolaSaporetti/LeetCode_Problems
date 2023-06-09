#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        rz = mat.size();
        cz = mat[0].size();
        map<int,vector<pair<int,int>>> m;
        vector<int> r(rz,0);
        vector<int> c(cz,0);
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) m[mat[i][j]].push_back({i,j});
        for(auto& [key,vals] : m)
        {
            map<int,int> t_row;
            map<int,int> t_col;
            for(auto& e : vals)
            {
                int row = e.first;
                int col = e.second;
                t_row[row] = max(t_row[row],max(r[row]+1,c[col]+1));
                t_col[col] = max(t_col[col],max(r[row]+1,c[col]+1));
            }
            for(auto& [key,val] : t_row) r[key]=val;
            for(auto& [key,val] : t_col) c[key]=val;
        }
        int res = 0;
        for(auto& e : r) res = max(res,e);
        for(auto& e : c) res = max(res,e);
        return res;
    }
private:
    int rz;
    int cz;
};