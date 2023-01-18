#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> m(n,vector<int>(n+1,0));
        vector<vector<int>> res(n,vector<int>(n,0));
        for(auto& q : queries)
        {
            for(int i=0;i<=q[2]-q[0];i++)
            {
                m[q[0]+i][q[1]]+=1;
                m[q[0]+i][q[3]+1]-=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            res[i][0]=m[i][0];
            for(int j=1;j<n;j++)
            {
                res[i][j]=m[i][j]+res[i][j-1];
            }
        }
        return res;
    }
};