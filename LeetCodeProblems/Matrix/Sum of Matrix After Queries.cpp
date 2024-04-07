#include <vector>
using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long rz = n;
        long long cz = n;
        vector<bool> r(n,false);
        vector<bool> c(n,false);
        long long res = 0;
        for(int i=queries.size()-1;i>=0;i--)
        {
            if(queries[i][0]==0 && !r[queries[i][1]])
            {
                r[queries[i][1]]=true;
                res+=(cz*(long long)queries[i][2]);
                rz--;
            }
            if(queries[i][0]==1 && !c[queries[i][1]])
            {
                c[queries[i][1]]=true;
                res+=(rz*(long long)queries[i][2]);
                cz--;
            }
        }
        return res;
    }
};