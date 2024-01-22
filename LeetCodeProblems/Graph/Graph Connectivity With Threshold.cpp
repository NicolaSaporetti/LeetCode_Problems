#include <vector>
#include "DisjoinSet.cpp"
using namespace std;


class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjoinSet ds(n+1);
        for(int j=threshold+1;j<=n/2;j++)
            for(int i=j*2;i<=n;i+=j) ds.connect_fast(j,i);
        vector<bool> res;
        for(auto& e : queries)
        {
            res.push_back(ds.are_connect(e[0],e[1]));
        }
        return res;
    }
};